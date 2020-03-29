$NetBSD: patch-src_passwd.c,v 1.1 2020/03/29 02:18:56 manu Exp $
--- src/passwd.c.orig	2020-03-28 02:26:07.941903613 +0000
+++ src/passwd.c	2020-03-28 02:26:17.315839015 +0000
@@ -19,8 +19,12 @@
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif
 
+#ifdef __NetBSD__
+#define NO_STATIC_MODULES
+#endif
+
 #include <security/pam_modules.h>
 
 extern int pam_sm_test(pam_handle_t *pamh, int flags, int argc, const char **argv);
 
