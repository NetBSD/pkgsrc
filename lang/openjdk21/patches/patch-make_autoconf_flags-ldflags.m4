$NetBSD: patch-make_autoconf_flags-ldflags.m4,v 1.1 2026/09/06 16:53:12 tnn Exp $

We need to use zero as buildjdk if the platform lacks hotspot support.

--- make/autoconf/flags-ldflags.m4.orig	2026-09-06 13:49:11.747735674 +0000
+++ make/autoconf/flags-ldflags.m4
@@ -41,7 +41,7 @@ AC_DEFUN([FLAGS_SETUP_LDFLAGS],
   # Setup the build toolchain
 
   # When building a buildjdk, it's always only the server variant
-  BUILD_JVM_VARIANT_PATH=server
+  BUILD_JVM_VARIANT_PATH=$JVM_VARIANT_MAIN
 
   FLAGS_SETUP_LDFLAGS_CPU_DEP([BUILD], [OPENJDK_BUILD_])
 
