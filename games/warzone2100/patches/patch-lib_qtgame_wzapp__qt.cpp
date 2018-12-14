$NetBSD: patch-lib_qtgame_wzapp__qt.cpp,v 1.1 2018/12/14 17:27:01 triaxx Exp $

The clip() function was not declared in the scope.

--- lib/qtgame/wzapp_qt.cpp.orig	2017-04-23 13:12:16.000000000 +0000
+++ lib/qtgame/wzapp_qt.cpp
@@ -42,6 +42,7 @@
 
 #include "lib/exceptionhandler/dumpinfo.h"
 #include "lib/framework/file.h"
+#include "lib/framework/math_ext.h"
 #include "lib/ivis_opengl/piestate.h"
 #include "lib/ivis_opengl/pieclip.h"
 #include "lib/ivis_opengl/screen.h"
