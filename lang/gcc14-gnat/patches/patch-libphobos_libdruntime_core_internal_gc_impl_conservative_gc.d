$NetBSD: patch-libphobos_libdruntime_core_internal_gc_impl_conservative_gc.d,v 1.1 2025/04/25 19:35:10 dkazankov Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- libphobos/libdruntime/core/internal/gc/impl/conservative/gc.d
+++ libphobos/libdruntime/core/internal/gc/impl/conservative/gc.d
@@ -30,8 +30,13 @@ module core.internal.gc.impl.conservative.gc;

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
