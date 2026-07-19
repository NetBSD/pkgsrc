$NetBSD: patch-libphobos_libdruntime_core_internal_gc_impl_conservative_gc.d,v 1.1 2026/07/19 11:17:45 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- libphobos/libdruntime/core/internal/gc/impl/conservative/gc.d.orig	2026-06-12 06:09:10.558026783 +0000
+++ libphobos/libdruntime/core/internal/gc/impl/conservative/gc.d
@@ -30,8 +30,13 @@ module core.internal.gc.impl.conservativ

 /***************************************************/
 version = COLLECT_PARALLEL;  // parallel scanning
-version (Posix)
-    version = COLLECT_FORK;
+version (GNU)
+{
+  version (linux)
+    version = COLLECT_FORK;  // uses clone(), battle tested and reliable
+}
+else version (Posix)
+  version = COLLECT_FORK;

 import core.internal.gc.bits;
 import core.internal.gc.os;
