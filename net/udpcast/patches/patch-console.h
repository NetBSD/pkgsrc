$NetBSD: patch-console.h,v 1.1 2017/02/18 13:59:01 joerg Exp $

--- console.h.orig	2017-02-18 01:54:31.092565508 +0000
+++ console.h
@@ -1,6 +1,7 @@
 #ifndef CONSOLE_H
 #define CONSOLE_H
 
+#include <sys/time.h>
 #ifdef __MINGW32__
 #include <winsock2.h>
 #include <winbase.h>
