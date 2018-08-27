$NetBSD: patch-src_secret.c,v 1.1 2018/08/27 15:14:03 wiz Exp $

Do not mask implementation defined extensions from the namespace.

--- src/secret.c.orig	2018-01-15 11:37:46.000000000 +0000
+++ src/secret.c
@@ -29,6 +29,9 @@
  * of the copyright holder.
  */
 
+/* Make implementation defined extensions visible here */
+#undef _POSIX_C_SOURCE
+
 /* C11 (if available) */
 #define __STDC_WANT_LIB_EXT1__ 1  /*!< Request for Annex K */
 
