$NetBSD: patch-src_main_util.c,v 1.1 2012/03/06 21:34:29 wiz Exp $

Fix build with pcre-8.30+.
Based on Petr Písař <ppisar@redhat.com>'s patch
http://pkgs.fedoraproject.org/gitweb/?p=R.git;a=commitdiff_plain

--- src/main/util.c.orig	2011-10-02 22:02:33.000000000 +0000
+++ src/main/util.c
@@ -1257,8 +1257,16 @@ Rboolean mbcsValid(const char *str)
 }
 
 #include "pcre.h"
+#if  PCRE_MAJOR > 8 || PCRE_MINOR >= 30
+extern int _pcre_valid_utf(const char *string, int length, int *erroroffset);
+
+Rboolean utf8Valid(const char *str)
+{
+    int errp;
+    return  (_pcre_valid_utf(str, (int) strlen(str), &errp) == 0);
+}
 /* This changed at 8.13: we don't allow < 8.0 */
-#if  PCRE_MAJOR > 8 || PCRE_MINOR >= 13
+#elif  PCRE_MAJOR > 8 || PCRE_MINOR >= 13
 extern int _pcre_valid_utf8(const char *string, int length, int *erroroffset);
 
 Rboolean utf8Valid(const char *str)
