$NetBSD: patch-support_signal.c,v 1.2 2014/11/30 08:40:51 spz Exp $

Add necessary includes on SunOS.

--- support/signal.c.orig	2014-09-22 13:23:09.000000000 +0000
+++ support/signal.c
@@ -31,6 +31,10 @@
 #include <mono/metadata/appdomain.h>
 #endif
 
+#ifdef __sun
+#include <siginfo.h>
+#endif
+
 G_BEGIN_DECLS
 
 typedef void (*mph_sighandler_t)(int);
