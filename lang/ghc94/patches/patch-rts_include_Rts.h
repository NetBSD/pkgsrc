$NetBSD: patch-rts_include_Rts.h,v 1.1 2023/01/24 02:49:26 pho Exp $

Fix build on FreeBSD:
https://gitlab.haskell.org/ghc/ghc/-/issues/22777

--- rts/include/Rts.h.orig	2022-12-23 16:19:02.000000000 +0000
+++ rts/include/Rts.h
@@ -167,7 +167,7 @@ void _warnFail(const char *filename, unsigned int line
 #endif /* DEBUG */
 
 #if __STDC_VERSION__ >= 201112L
-#define GHC_STATIC_ASSERT(x, msg) static_assert((x), msg)
+#define GHC_STATIC_ASSERT(x, msg) _Static_assert((x), msg)
 #else
 #define GHC_STATIC_ASSERT(x, msg)
 #endif
