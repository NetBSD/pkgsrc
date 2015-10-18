$NetBSD: patch-src_hugin1_icpfind_AutoCtrlPointCreator.cpp,v 1.2 2015/10/18 15:56:56 adam Exp $

Fix building with Clang.

--- src/hugin1/icpfind/AutoCtrlPointCreator.cpp.orig	2014-06-14 11:02:49.000000000 +0000
+++ src/hugin1/icpfind/AutoCtrlPointCreator.cpp
@@ -28,7 +28,7 @@
 #include "panoinc.h"
 
 #include <fstream>
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
 #include <ext/stdio_filebuf.h>
 #endif
 
