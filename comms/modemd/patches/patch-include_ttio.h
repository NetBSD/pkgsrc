$NetBSD: patch-include_ttio.h,v 1.1 2025/12/18 13:32:20 nia Exp $

Add missing include for sleep(3).

--- include/ttio.h.orig	2025-12-18 13:21:08.539221227 +0000
+++ include/ttio.h
@@ -42,6 +42,8 @@
 #include <termios.h>
 #endif
 
+#include <unistd.h>
+
 #ifndef CVT_TTYNAME
 #define CVT_TTYNAME(buf, name) sprintf (buf, "/dev/%s", name)
 #endif
