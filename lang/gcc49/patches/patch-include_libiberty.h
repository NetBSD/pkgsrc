$NetBSD: patch-include_libiberty.h,v 1.1 2014/09/04 18:43:11 jperkin Exp $

Support DragonFly.

--- include/libiberty.h.orig	2014-01-21 15:09:10.000000000 +0000
+++ include/libiberty.h
@@ -106,7 +106,7 @@ extern int countargv (char**);
    to find the declaration so provide a fully prototyped one.  If it
    is 1, we found it so don't provide any declaration at all.  */
 #if !HAVE_DECL_BASENAME
-#if defined (__GNU_LIBRARY__ ) || defined (__linux__) || defined (__FreeBSD__) || defined (__OpenBSD__) || defined(__NetBSD__) || defined (__CYGWIN__) || defined (__CYGWIN32__) || defined (__MINGW32__) || defined (HAVE_DECL_BASENAME)
+#if defined (__GNU_LIBRARY__ ) || defined (__linux__) || defined (__DragonFly__) || defined (__FreeBSD__) || defined (__OpenBSD__) || defined(__NetBSD__) || defined (__CYGWIN__) || defined (__CYGWIN32__) || defined (__MINGW32__) || defined (HAVE_DECL_BASENAME)
 extern char *basename (const char *) ATTRIBUTE_RETURNS_NONNULL ATTRIBUTE_NONNULL(1);
 #else
 /* Do not allow basename to be used if there is no prototype seen.  We
