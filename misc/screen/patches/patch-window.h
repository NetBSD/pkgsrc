$NetBSD: patch-window.h,v 1.4 2025/01/09 20:07:04 ktnb Exp $

OpenBSD grumbles without the socket definitions

--- window.h.orig	2025-01-09 02:59:07.553319622 +0000
+++ window.h
@@ -33,6 +33,9 @@
 #ifndef SCREEN_WINDOW_H
 #define SCREEN_WINDOW_H
 
+#ifdef __OpenBSD__
+#include <sys/socket.h>
+#endif
 #include "config.h"
 
 #include "sched.h"
