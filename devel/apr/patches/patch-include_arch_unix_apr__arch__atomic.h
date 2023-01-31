$NetBSD: patch-include_arch_unix_apr__arch__atomic.h,v 1.2 2023/01/31 18:41:49 wiz Exp $

Work around missing 64bit atomic builtins for non-x86 ILP32 platforms.

--- include/arch/unix/apr_arch_atomic.h.orig	2022-06-27 21:55:09.000000000 +0000
+++ include/arch/unix/apr_arch_atomic.h
@@ -26,6 +26,9 @@
 /* noop */
 #elif HAVE_ATOMIC_BUILTINS
 #   define USE_ATOMICS_BUILTINS
+#   ifndef __LP64__
+#	define NEED_ATOMICS_GENERIC64
+#   endif
 #   if HAVE_ATOMIC_BUILTINS64
 #   define USE_ATOMICS_BUILTINS64
 #   else
