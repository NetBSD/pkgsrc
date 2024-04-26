$NetBSD: patch-libgcc_libgcov.h,v 1.1 2024/04/26 13:05:01 micha Exp $

System include directory is not searched, even if "sys/mman.h" header
file is present. Quoted from "libgcc/configure.ac":
| The libgcc should not depend on any header files
=> Redefine HAVE_SYS_MMAN_H to zero.

--- libgcc/libgcov.h.orig	2022-05-06 07:30:59.000000000 +0000
+++ libgcc/libgcov.h
@@ -45,6 +45,12 @@
 #include "libgcc_tm.h"
 #include "gcov.h"
 
+// ----------------------------------
+// pkgsrc patch
+#undef HAVE_SYS_MMAN_H
+#define HAVE_SYS_MMAN_H  0
+// ----------------------------------
+
 #if HAVE_SYS_MMAN_H
 #include <sys/mman.h>
 #endif
