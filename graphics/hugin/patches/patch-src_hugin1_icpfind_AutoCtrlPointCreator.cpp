$NetBSD: patch-src_hugin1_icpfind_AutoCtrlPointCreator.cpp,v 1.3 2016/04/07 19:23:26 adam Exp $

Fix building with Clang.

--- src/hugin1/icpfind/AutoCtrlPointCreator.cpp.orig	2016-02-19 22:03:11.000000000 +0000
+++ src/hugin1/icpfind/AutoCtrlPointCreator.cpp
@@ -28,7 +28,7 @@
 #include "panoinc.h"
 
 #include <fstream>
-#if defined (__GNUC__) && !defined (__FreeBSD__)
+#if defined(__GNUC__) && !defined(__FreeBSD__) && !defined(__clang__)
 #include <ext/stdio_filebuf.h>
 #endif
 
