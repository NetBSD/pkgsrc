$NetBSD: patch-include_arch_unix_apr__arch__atomic.h,v 1.1 2020/02/20 06:25:28 rin Exp $

Work around missing 64bit atomic builtins for non-x86 ILP32 platforms.

--- include/arch/unix/apr_arch_atomic.h.orig	2020-02-19 15:50:52.065380193 +0900
+++ include/arch/unix/apr_arch_atomic.h	2020-02-19 15:51:59.253483287 +0900
@@ -26,6 +26,9 @@
 /* noop */
 #elif HAVE_ATOMIC_BUILTINS
 #   define USE_ATOMICS_BUILTINS
+#   ifndef __LP64__
+#	define NEED_ATOMICS_GENERIC64
+#   endif
 #elif defined(SOLARIS2) && SOLARIS2 >= 10
 #   define USE_ATOMICS_SOLARIS
 #   define NEED_ATOMICS_GENERIC64
