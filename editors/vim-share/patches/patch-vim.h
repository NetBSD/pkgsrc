$NetBSD: patch-vim.h,v 1.1 2025/05/05 15:05:27 schmonz Exp $

Fix Tiger build.

--- src/vim.h.orig	2025-03-15 09:19:48.000000000 +0000
+++ src/vim.h
@@ -2316,7 +2316,7 @@ typedef struct stat stat_T;
 # define ATTRIBUTE_FORMAT_PRINTF(fmt_idx, arg_idx)
 #endif
 
-#if defined(__GNUC__) || defined(__clang__)
+#if (defined(__GNUC__) && ((__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3))) || defined(__clang__)
 # define likely(x)	__builtin_expect((x), 1)
 # define unlikely(x)	__builtin_expect((x), 0)
 # define ATTRIBUTE_COLD	__attribute__((cold))
