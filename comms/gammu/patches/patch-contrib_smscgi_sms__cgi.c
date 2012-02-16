$NetBSD: patch-contrib_smscgi_sms__cgi.c,v 1.1 2012/02/16 17:13:03 hans Exp $

--- contrib/smscgi/sms_cgi.c.orig	2009-09-08 09:57:12.000000000 +0200
+++ contrib/smscgi/sms_cgi.c	2012-01-25 19:47:48.177845692 +0100
@@ -26,6 +26,10 @@
 #include <signal.h>
 #include <sys/wait.h>
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #include "sms_cgi.h"
 
 /* Some systems let waitpid(2) tell callers about stopped children. */
