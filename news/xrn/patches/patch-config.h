$NetBSD: patch-config.h,v 1.1 2018/11/10 20:03:40 wiz Exp $

Insert pkgsrc default configuration.

--- config.h.orig	2018-08-23 17:17:58.000000000 +0000
+++ config.h
@@ -30,6 +30,16 @@
  * config.h: configurable defaults
  */
 
+/* pkgsrc configuration */
+/* -------------------------------------------------------------------- */
+#define ALLOW_RESOURCE_PASSWORDS 0
+#define CROSSPOST_CONFIRM 5
+#define FOLLOWUPTO_CONFIRM 2
+#define SENDMAIL "/usr/sbin/sendmail -oi -t"
+#define SENDMAIL_VERIFY "/usr/sbin/sendmail -bv >/dev/null"
+/* -------------------------------------------------------------------- */
+
+
 #ifndef CONFIG_H_IS_OK
 #error "You must edit config.h appropriately for your site!"
 #endif
