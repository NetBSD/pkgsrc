$NetBSD: patch-src_StelMainGraphicsView.cpp,v 1.2 2013/08/09 11:47:57 drochner Exp $

--- src/StelMainGraphicsView.cpp.orig	2013-08-04 06:20:27.000000000 +0000
+++ src/StelMainGraphicsView.cpp
@@ -42,6 +42,7 @@
 #include <QThread>
 #include <QTimer>
 #include <QDir>
+#include <clocale>
 
 #ifndef DISABLE_SCRIPTING
  #include "StelScriptMgr.hpp"
