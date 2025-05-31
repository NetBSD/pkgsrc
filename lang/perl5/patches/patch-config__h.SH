$NetBSD: patch-config__h.SH,v 1.1 2025/05/31 19:22:30 wiz Exp $

https://github.com/Perl/perl5/issues/23010
https://github.com/Perl/perl5/commit/918bfff86ca8d6d4e4ec5b30994451e0bd74aba9.patch

--- config_h.SH.orig	2025-03-30 10:35:38.000000000 +0000
+++ config_h.SH
@@ -142,6 +142,12 @@ sed <<!GROK!THIS! >$CONFIG_H -e 's!^#und
  */
 #$d_fcntl HAS_FCNTL		/**/
 
+/* HAS_FDOPENDIR:
+ * This symbol, if defined, indicates that the fdopen routine is
+ * available to open a directory descriptor.
+ */
+#$d_fdopendir HAS_FDOPENDIR		/**/
+
 /* HAS_FGETPOS:
  *	This symbol, if defined, indicates that the fgetpos routine is
  *	available to get the file position indicator, similar to ftell().
