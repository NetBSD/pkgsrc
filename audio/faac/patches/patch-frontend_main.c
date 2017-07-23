$NetBSD: patch-frontend_main.c,v 1.1 2017/07/23 16:01:14 adam Exp $

Add missing include.

--- frontend/main.c.orig	2017-07-21 13:45:15.000000000 +0000
+++ frontend/main.c
@@ -31,6 +31,7 @@
 #include <windows.h>
 #include <fcntl.h>
 #else
+#include <sys/param.h>
 #include <signal.h>
 #endif
 
