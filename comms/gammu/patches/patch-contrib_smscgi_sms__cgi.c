$NetBSD: patch-contrib_smscgi_sms__cgi.c,v 1.3 2015/08/17 16:42:53 leot Exp $

Fix build on SunOS.

--- contrib/smscgi/sms_cgi.c.orig	2015-08-14 12:32:29.000000000 +0000
+++ contrib/smscgi/sms_cgi.c
@@ -28,6 +28,10 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
+ 
+#ifdef __sun
+#include <alloca.h>
+#endif
 
 #include "sms_cgi.h"
 
