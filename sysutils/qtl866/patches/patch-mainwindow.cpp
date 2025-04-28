$NetBSD: patch-mainwindow.cpp,v 1.1 2025/04/28 12:16:35 hauke Exp $

Get devices list directly from minipro tool 
From <https://github.com/wd5gnr/qtl866/pull/15>

fix: signal and slot name, from 
<https://github.com/wd5gnr/qtl866/commit/a5ce75138005a799562e353ec0fcc7cf31b6b268>

--- mainwindow.cpp.orig	2017-04-05 04:34:13.000000000 +0000
+++ mainwindow.cpp
@@ -45,13 +45,20 @@ MainWindow::MainWindow(QWidget *parent) 
     QMainWindow(parent),
     ui(new Ui::MainWindow)
 {
-    unsigned int i;
     QString selected;
     QSettings settings;
-    selected=settings.value("session/seldevice","PIC16F886").toString();
+    QString cmd=settings.value("options/command","minipro").toString();
+    selected=settings.value("session/seldevice","PIC16F88").toString();
     ui->setupUi(this);
-    for (i=0;i<sizeof(devnames)/sizeof(devnames[0]);i++)
-        ui->device->addItem(devnames[i],devnames[i]);
+    QProcess proc(this);
+    proc.setReadChannel(QProcess::StandardOutput);
+    proc.start(cmd, QStringList() << "-l");
+    proc.waitForFinished();
+    devices=QString(proc.readAllStandardOutput()).split("\n");
+    if(devices.empty()){
+        QMessageBox::critical(this,tr("Error"),tr("Can't get supported devices from minipro"));
+    }
+    ui->device->addItems(devices);
     ui->device->setCurrentText(selected);
     ui->filename->setText(settings.value("session/filename","").toString());
     ui->useisp->setChecked(settings.value("session/isp",false).toBool());
@@ -124,17 +131,17 @@ void MainWindow::shellAppend(QString col
     statusBar()->showMessage(text.split('\n').last());
 }
 
-void MainWindow::on_process_stderr()
+void MainWindow::onProcessStderr()
 {
     shellAppend("red", slave->readAllStandardError());
 }
 
-void MainWindow::on_process_stdout()
+void MainWindow::onProcessStdout()
 {
     shellAppend("black", slave->readAllStandardOutput());
 }
 
-void MainWindow::on_process_error(QProcess::ProcessError)
+void MainWindow::onProcessError(QProcess::ProcessError)
 {
     QProcess *process = qobject_cast<QProcess*>(sender());
     QMessageBox error(this);
@@ -147,7 +154,6 @@ void MainWindow::on_process_error(QProce
 
 void MainWindow::on_exec_clicked()
 {
-    unsigned int i;
     bool found=false;
     bool reading=true;
     QSettings settings;
@@ -163,13 +169,8 @@ void MainWindow::on_exec_clicked()
     }
     // TODO: detect .hex .srec etc and convert to temporary file on write (or could do this in script)
     devname=ui->device->currentText();
-    for (i=0;i<sizeof(devnames)/sizeof(devnames[0]);i++)
-    {
-        if (!strcmp(devname.toStdString().c_str(),devnames[i]))
-        {
-            found=true;
-            break;
-        }
+    if(devices.contains(devname)){
+        found=true;
     }
     if (!found)
     {
@@ -231,9 +232,9 @@ void MainWindow::on_exec_clicked()
     ui->controls->setEnabled(false);
     slave=new QProcess(this);
     connect(slave,SIGNAL(finished(int)),this,SLOT(on_finished(int)));
-    connect(slave, SIGNAL(error(QProcess::ProcessError)), this, SLOT(on_process_error(QProcess::ProcessError)));
-    connect(slave, SIGNAL(readyReadStandardOutput()), this, SLOT(on_process_stdout()));
-    connect(slave, SIGNAL(readyReadStandardError()), this, SLOT(on_process_stderr()));
+    connect(slave, SIGNAL(errorOccurred(QProcess::ProcessError)), this, SLOT(onProcessError(QProcess::ProcessError)));
+    connect(slave, SIGNAL(readyReadStandardOutput()), this, SLOT(onProcessStdout()));
+    connect(slave, SIGNAL(readyReadStandardError()), this, SLOT(onProcessStderr()));
 
     qDebug() << "Executing" << cmd << args;
     slave->start(cmd, args, QProcess::ReadWrite|QProcess::Unbuffered);
