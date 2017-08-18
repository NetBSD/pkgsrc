$NetBSD: patch-src_grip.c,v 1.1 2017/08/18 12:21:29 triaxx Exp $

Add system dependent headers.

--- src/grip.c.orig	2017-07-31 21:04:12.000000000 +0000
+++ src/grip.c
@@ -26,6 +26,9 @@
 #include <stdio.h>
 #include <unistd.h>
 #include <sys/param.h>
+#if defined(__NetBSD__)
+#include <sys/wait.h>
+#endif
 #include <gdk/gdkx.h>
 #include <X11/Xlib.h>
 #include <time.h>
