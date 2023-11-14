$NetBSD: patch-src_core_settings.h,v 1.1 2023/11/14 17:57:41 nia Exp $

NetBSD (and more POSIX platforms) support.

--- src/core/settings.h.orig	2023-08-12 04:46:09.000000000 +0000
+++ src/core/settings.h
@@ -417,7 +417,9 @@ struct Settings
 
 #ifdef WITH_RECOMPILER
   static constexpr CPUExecutionMode DEFAULT_CPU_EXECUTION_MODE = CPUExecutionMode::Recompiler;
-#ifdef WITH_MMAP_FASTMEM
+#ifdef __NetBSD__
+  static constexpr CPUFastmemMode DEFAULT_CPU_FASTMEM_MODE = CPUFastmemMode::Disabled;
+#elif defined(WITH_MMAP_FASTMEM)
   static constexpr CPUFastmemMode DEFAULT_CPU_FASTMEM_MODE = CPUFastmemMode::MMap;
 #else
   static constexpr CPUFastmemMode DEFAULT_CPU_FASTMEM_MODE = CPUFastmemMode::LUT;
