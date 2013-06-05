$NetBSD: patch-support_signal.c,v 1.1 2013/06/05 17:03:55 jperkin Exp $

Add necessary includes on SunOS.

--- support/signal.c.orig	2013-04-25 09:01:58.000000000 +0000
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
