$NetBSD: patch-src_cpuinfo__x86.c,v 1.1 2020/12/14 15:07:49 tnn Exp $

Use /proc/cpuinfo on NetBSD/x86 for now.

--- src/cpuinfo_x86.c.orig	2020-10-15 09:09:51.000000000 +0000
+++ src/cpuinfo_x86.c
@@ -1,3 +1,4 @@
+
 // Copyright 2017 Google LLC
 // Copyright 2020 Intel Corporation
 //
@@ -97,7 +98,7 @@
 // microarchitectures.
 #if defined(CPU_FEATURES_OS_WINDOWS)
 #include <windows.h>  // IsProcessorFeaturePresent
-#elif defined(CPU_FEATURES_OS_LINUX_OR_ANDROID)
+#elif defined(CPU_FEATURES_OS_LINUX_OR_ANDROID) || defined(CPU_FEATURES_OS_NETBSD)
 #include "internal/filesystem.h"         // Needed to parse /proc/cpuinfo
 #include "internal/stack_line_reader.h"  // Needed to parse /proc/cpuinfo
 #include "internal/string_view.h"        // Needed to parse /proc/cpuinfo
@@ -1239,7 +1240,7 @@ static void DetectSseViaOs(X86Features* 
   features->ssse3 = GetDarwinSysCtlByName("hw.optional.supplementalsse3");
   features->sse4_1 = GetDarwinSysCtlByName("hw.optional.sse4_1");
   features->sse4_2 = GetDarwinSysCtlByName("hw.optional.sse4_2");
-#elif defined(CPU_FEATURES_OS_LINUX_OR_ANDROID)
+#elif defined(CPU_FEATURES_OS_LINUX_OR_ANDROID) || defined(CPU_FEATURES_OS_NETBSD)
   // Handling Linux platform through /proc/cpuinfo.
   const int fd = CpuFeatures_OpenFile("/proc/cpuinfo");
   if (fd >= 0) {
