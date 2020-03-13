$NetBSD: patch-gfx_skia_skia_src_core_SkCpu.cpp,v 1.1 2020/03/13 17:59:27 wiz Exp $

NetBSD/aarch64 doesn't have <sys/auxv.h>.

--- gfx/skia/skia/src/core/SkCpu.cpp.orig	2019-03-05 00:32:47.658232017 +0900
+++ gfx/skia/skia/src/core/SkCpu.cpp	2019-03-05 00:33:10.203589997 +0900
@@ -70,7 +70,7 @@
         return features;
     }
 
-#elif defined(SK_CPU_ARM64) && __has_include(<sys/auxv.h>)
+#elif defined(SK_CPU_ARM64) && __has_include(<sys/auxv.h>) && !defined(__NetBSD__)
     #include <sys/auxv.h>
 
     static uint32_t read_cpu_features() {
