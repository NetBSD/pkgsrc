$NetBSD: patch-vim.h,v 1.3 2025/12/03 22:52:01 morr Exp $

Fix Tiger build.

--- src/vim.h.orig	2025-12-03 21:01:37.000000000 +0000
+++ src/vim.h
@@ -2385,7 +2385,7 @@ typedef struct soundcb_S soundcb_T;
 # define ATTRIBUTE_FORMAT_PRINTF(fmt_idx, arg_idx)
 #endif
 
-#if defined(__GNUC__) || defined(__clang__)
+#if (defined(__GNUC__) && ((__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3))) || defined(__clang__)
 # define likely(x)	__builtin_expect((x), 1)
 # define unlikely(x)	__builtin_expect((x), 0)
 # define ATTRIBUTE_COLD	__attribute__((cold))
