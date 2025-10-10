$NetBSD: patch-lib_glob_smatch.c,v 1.1 2025/10/10 20:48:02 js Exp $

--- lib/glob/smatch.c.orig	2023-05-29 18:15:17.000000000 +0000
+++ lib/glob/smatch.c
@@ -137,6 +137,8 @@ rangecmp (int c1, int c2, int forcecoll)
 #endif /* !HAVE_STRCOLL */
 
 #if defined (HAVE_STRCOLL)
+extern int locale_utf8locale;
+
 /* Returns 1 if chars C and EQUIV collate equally in the current locale. */
 static int
 collseqcmp (int c, int equiv)
