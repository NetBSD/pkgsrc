$NetBSD: patch-gjs_jsapi-util.cpp,v 1.1 2020/11/10 11:33:50 nia Exp $

Fix va_list error

--- gjs/jsapi-util.cpp.orig	2020-10-08 22:26:17.390874100 +0000
+++ gjs/jsapi-util.cpp
@@ -26,6 +26,7 @@
 
 #include <stdio.h>   // for sscanf
 #include <string.h>  // for strlen
+#include <stdarg.h>
 
 #ifdef _WIN32
 #    define WIN32_LEAN_AND_MEAN
