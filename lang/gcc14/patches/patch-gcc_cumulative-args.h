$NetBSD: patch-gcc_cumulative-args.h,v 1.1 2025/02/05 16:30:36 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- /dev/null
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
