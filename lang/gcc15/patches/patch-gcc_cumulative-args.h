$NetBSD: patch-gcc_cumulative-args.h,v 1.1 2026/07/19 11:17:44 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- gcc/cumulative-args.h.orig	2026-07-19 09:48:42.226913605 +0000
+++ gcc/cumulative-args.h
@@ -0,0 +1,20 @@
+#ifndef GCC_CUMULATIVE_ARGS_H
+#define GCC_CUMULATIVE_ARGS_H
+
+#if CHECKING_P
+
+struct cumulative_args_t { void *magic; void *p; };
+
+#else /* !CHECKING_P */
+
+/* When using a GCC build compiler, we could use
+   __attribute__((transparent_union)) to get cumulative_args_t function
+   arguments passed like scalars where the ABI would mandate a less
+   efficient way of argument passing otherwise.  However, that would come
+   at the cost of less type-safe !CHECKING_P compilation.  */
+
+union cumulative_args_t { void *p; };
+
+#endif /* !CHECKING_P */
+
+#endif /* GCC_CUMULATIVE_ARGS_H */
