$NetBSD: patch-xbmc_utils_CPUInfo.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/utils/CPUInfo.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/utils/CPUInfo.cpp
@@ -36,7 +36,7 @@
 #endif
 #endif
 
-#if defined(TARGET_FREEBSD)
+#if defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #include <sys/resource.h>
@@ -234,7 +234,7 @@ CCPUInfo::CCPUInfo(void)
   }
   else
     m_cpuQueryLoad = NULL;
-#elif defined(TARGET_FREEBSD)
+#elif defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
   size_t len;
   int i;
   char cpumodel[512];
@@ -538,6 +538,8 @@ float CCPUInfo::getCPUFrequency()
   if (sysctlbyname("dev.cpu.0.freq", &hz, &len, NULL, 0) != 0)
     hz = 0;
   return (float)hz;
+#elif defined(TARGET_NETBSD)
+  return 0.f;
 #else
   int value = 0;
   if (m_fCPUFreq && !m_cpuInfoForFreq)
@@ -758,6 +760,8 @@ bool CCPUInfo::readProcStat(unsigned lon
     }
   }
   free(cptimes);
+#elif defined(TARGET_NETBSD)
+  return false;
 #else
   if (m_fProcStat == NULL)
     return false;
