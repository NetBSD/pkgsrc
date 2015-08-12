$NetBSD: patch-include_LibreOfficeKit_LibreOfficeKitInit.h,v 1.1 2015/08/12 00:57:20 ryoon Exp $

--- include/LibreOfficeKit/LibreOfficeKitInit.h.orig	2015-07-31 00:32:43.000000000 +0000
+++ include/LibreOfficeKit/LibreOfficeKitInit.h
@@ -17,7 +17,7 @@ extern "C"
 {
 #endif
 
-#if defined(__linux__) || defined (__FreeBSD_kernel__) || defined(_AIX) || defined(_WIN32) || defined(__APPLE__)
+#if defined(__linux__) || defined (__FreeBSD_kernel__) || defined(_AIX) || defined(_WIN32) || defined(__APPLE__) || defined (__NetBSD__)
 
 #include <stdio.h>
 #include <stdlib.h>
