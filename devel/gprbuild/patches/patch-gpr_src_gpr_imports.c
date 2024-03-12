$NetBSD: patch-gpr_src_gpr_imports.c,v 1.1 2024/03/12 17:50:13 wiz Exp $

Add support for NetBSD (same as for FreeBSD) and fix getrusage() warning at linking stage

--- gpr/src/gpr_imports.c.orig	2023-10-09 21:31:11.000000000 +0300
+++ gpr/src/gpr_imports.c	2023-12-21 19:52:58.220771312 +0200
@@ -64,6 +64,15 @@
 char __gnat_shared_libgcc_default = STATIC;
 const char *__gnat_default_libgcc_subdir = "lib";
 
+#elif defined(__NetBSD__)
+int __gnat_link_max = 8192;
+char __gnat_shared_libgcc_default = STATIC;
+const char *__gnat_default_libgcc_subdir = "lib";
+#include "sys/resource.h"
+int __netbsd_getrusage(int who, struct rusage *rusage) {
+    return getrusage(who, rusage);
+}
+
 #elif defined (__APPLE__)
 int __gnat_link_max = 262144;
 char __gnat_shared_libgcc_default = SHARED;
