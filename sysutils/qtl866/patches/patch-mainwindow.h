$NetBSD: patch-mainwindow.h,v 1.1 2025/04/28 12:16:35 hauke Exp $

fix: signal and slot name, from 
<https://github.com/wd5gnr/qtl866/commit/a5ce75138005a799562e353ec0fcc7cf31b6b268>

Get devices list directly from minipro tool 
From <https://github.com/wd5gnr/qtl866/pull/15>

--- mainwindow.h.orig	2017-04-05 04:34:13.000000000 +0000
+++ mainwindow.h
@@ -42,10 +42,10 @@ private slots:
 
     void on_exec_clicked();
 
-    void on_process_error(QProcess::ProcessError);
+    void onProcessError(QProcess::ProcessError);
     void on_finished(int code);
-    void on_process_stdout();
-    void on_process_stderr();
+    void onProcessStdout();
+    void onProcessStderr();
 
     void on_action_About_triggered();
 
@@ -61,6 +61,7 @@ private:
 
     Ui::MainWindow *ui;
     QProcess *slave;
+    QStringList devices;
 };
 
 #endif // MAINWINDOW_H
