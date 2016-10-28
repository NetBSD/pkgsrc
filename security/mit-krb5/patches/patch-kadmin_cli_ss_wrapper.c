$NetBSD: patch-kadmin_cli_ss_wrapper.c,v 1.1 2016/10/28 20:56:14 tez Exp $

Fix build on OS X (missing time_t definition)


--- kadmin/cli/ss_wrapper.c.orig	2016-10-19 17:10:41.000000000 -0500
+++ kadmin/cli/ss_wrapper.c	2016-10-19 17:09:41.000000000 -0500
@@ -23,6 +23,7 @@
  * or implied warranty.
  */
 
+#include <k5-int.h>
 #include <k5-platform.h>
 #include <krb5.h>
 #include <locale.h>
