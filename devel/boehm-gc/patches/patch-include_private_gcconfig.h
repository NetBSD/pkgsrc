$NetBSD: patch-include_private_gcconfig.h,v 1.3 2018/05/18 23:04:53 jmcneill Exp $

--- include/private/gcconfig.h.orig	2018-01-26 13:16:17.000000000 +0000
+++ include/private/gcconfig.h
@@ -114,7 +114,7 @@
 # endif
 # if defined(__aarch64__)
 #    define AARCH64
-#    if !defined(LINUX) && !defined(DARWIN) && !defined(FREEBSD)
+#    if !defined(LINUX) && !defined(DARWIN) && !defined(FREEBSD) && !defined(NETBSD)
 #      define NOSYS
 #      define mach_type_known
 #    endif
@@ -165,6 +165,10 @@
 #    define ARM32
 #    define mach_type_known
 # endif
+# if defined(NETBSD) && defined(__aarch64__)
+#    define AARCH64
+#    define mach_type_known
+# endif
 # if defined(NETBSD) && defined(__sh__)
 #    define SH
 #    define mach_type_known
@@ -2143,6 +2147,14 @@
 #   ifndef HBLKSIZE
 #     define HBLKSIZE 4096
 #   endif
+#   ifdef NETBSD
+#     define OS_TYPE "NETBSD"
+#     define HEURISTIC2
+      extern ptr_t GC_data_start;
+#     define DATASTART GC_data_start
+#     define ELF_CLASS ELFCLASS64
+#     define DYNAMIC_LOADING
+#   endif
 #   ifdef LINUX
 #     define OS_TYPE "LINUX"
 #     define LINUX_STACKBOTTOM
