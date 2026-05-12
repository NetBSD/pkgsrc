$NetBSD: patch-vim.h,v 1.3.4.1 2026/05/12 19:22:01 bsiegert Exp $

Fix Tiger build.

--- src/vim.h.orig	2026-05-06 18:17:00.000000000 +0000
+++ src/vim.h
@@ -2390,7 +2390,7 @@ typedef struct soundcb_S soundcb_T;
 # define ATTRIBUTE_FORMAT_PRINTF(fmt_idx, arg_idx)
 #endif
 
-#if defined(__GNUC__) || defined(__clang__)
+#if (defined(__GNUC__) && ((__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3))) || defined(__clang__)
 # define likely(x)	__builtin_expect((x), 1)
 # define unlikely(x)	__builtin_expect((x), 0)
 # define ATTRIBUTE_COLD	__attribute__((cold))
