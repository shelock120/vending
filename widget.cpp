#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    money_ = 0;
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::setControl()
{
    ui->lcdNumber->display(money_);
    ui->pbcafe->setEnabled(money_ >= 100);
    ui->pbTea->setEnabled(money_ >= 150);
    ui->pbcola->setEnabled(money_ >= 200);
}


void Widget::on_pb500_clicked()
{
    money_ += 500;
    setControl();
}


void Widget::on_pb100_clicked()
{
    money_ += 100;
    setControl();
}

void Widget::on_pb50_clicked()
{
    money_ += 50;
    setControl();
}

void Widget::on_pb10_clicked()
{
    money_ += 10;
    setControl();
}

void Widget::on_pbcafe_clicked()
{
    money_ -= 100;
    setControl();
}

void Widget::on_pbTea_clicked()
{
    money_ -= 150;
    setControl();
}

void Widget::on_pbcola_clicked()
{
    money_ -= 200;
    setControl();
}

void Widget::on_pbreset_clicked()
{


    QMessageBox Msgbox;
        int dhqor = money_/500;
        int qor = (money_%500)/100;
        int dhtlq = (money_%100)/50;
        int tlq = (money_%50)/10;
        Msgbox.setInformativeText(QString("500 : %1\n100 : %2\n50  : %3\n10  : %4\n").arg(dhqor).arg(qor).arg(dhtlq).arg(tlq));
        Msgbox.exec();
    money_ = 0;
    setControl();
}
