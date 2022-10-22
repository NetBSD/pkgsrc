$NetBSD: patch-src-c_native_ptrdiff__t.h,v 1.1 2022/10/22 17:18:36 he Exp $

The config check sets CHECKSEUM_STDDEF or CHECKSEUM_NO_STDDEF
but nothing sets _STDDEF_H.  Make this consistent.

--- src-c/native/ptrdiff_t.h.orig	2022-04-08 14:29:14.000000000 +0000
+++ src-c/native/ptrdiff_t.h
@@ -1,7 +1,7 @@
 #ifndef CHECKSEUM_PTRDIFF_T
 #define CHECKSEUM_PTRDIFF_T
 
-#if defined(_STDDEF_H)
+#if defined(CHECKSEUM_STDDEF)
 #  include <stddef.h>
 #elif defined(_WIN32)
 #  include <CRTDEFS.H>
