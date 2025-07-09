$NetBSD: patch-src_stdlib_SDL__iconv.c,v 1.1 2025/07/09 09:56:28 jperkin Exp $

Default to non-const iconv() to fix the majority of systems with GCC 14.

--- src/stdlib/SDL_iconv.c.orig	2012-01-19 06:30:06.000000000 +0000
+++ src/stdlib/SDL_iconv.c
@@ -31,11 +31,12 @@
 /* Depending on which standard the iconv() was implemented with,
    iconv() may or may not use const char ** for the inbuf param.
    If we get this wrong, it's just a warning, so no big deal.
+
+   This is no longer true with GCC 14, which turns this into an
+   error.  In lieu of a proper configure test we simply go with
+   non const by default as that is what the vast majority use.
 */
-#if defined(_XGP6) || \
-    defined(__GLIBC__) && ((__GLIBC__ > 2) || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 2))
 #define ICONV_INBUF_NONCONST
-#endif
 
 #include <errno.h>
 
