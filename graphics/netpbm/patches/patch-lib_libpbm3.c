$NetBSD: patch-lib_libpbm3.c,v 1.1 2011/04/04 09:17:24 adam Exp $

Clang does not support SSE extensions at the moment.

--- lib/libpbm3.c.orig	2011-03-29 09:31:31.000000000 +0000
+++ lib/libpbm3.c
@@ -23,7 +23,7 @@
 #if defined(__GNUC__) && \
   (__GNUC__ * 100 + __GNUC_MINOR__ >= 301) && \
   (__GNUC__ * 100 + __GNUC_MINOR__ < 403) && \
-  defined (__SSE__)
+  defined (__SSE__) && !defined(__clang__)
 /* GCC 4.3 does have the facility, but it is different from what this
    code knows how to use.  In particular, the calls to
    __builtin_ia32_pcmpeqb() and __builtin_ia32_pmovmskb() fail to
