$NetBSD: patch-src_layApplication.cc,v 1.3 2018/07/24 13:00:10 ryoon Exp $

To avoid following message
error: 'struct sigaction' has no member named 'sa_restorer'

--- src/lay/lay/layApplication.cc.orig	2017-11-08 04:48:15.000000000 +0900
+++ src/lay/lay/layApplication.cc	2017-11-17 20:32:08.822834411 +0900
@@ -65,6 +65,7 @@
 #include <QAction>
 #include <QMessageBox>
 
+#include <unistd.h>
 #include <iostream>
 #include <memory>
 #include <algorithm>
