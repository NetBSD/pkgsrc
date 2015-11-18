$NetBSD: patch-xbmc_utils_SystemInfo.cpp,v 1.2 2015/11/18 23:27:23 jmcneill Exp $

--- xbmc/utils/SystemInfo.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/utils/SystemInfo.cpp
@@ -66,7 +66,7 @@
 #elif defined(TARGET_ANDROID)
 #include <android/api-level.h>
 #include <sys/system_properties.h>
-#elif defined(TARGET_FREEBSD)
+#elif defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
 #include <sys/param.h>
 #elif defined(TARGET_LINUX)
 #include <linux/version.h>
@@ -607,8 +607,8 @@ std::string CSysInfo::GetOsName(bool emp
   {
 #if defined (TARGET_WINDOWS)
     osName = GetKernelName() + "-based OS";
-#elif defined(TARGET_FREEBSD)
-    osName = GetKernelName(true); // FIXME: for FreeBSD OS name is a kernel name
+#elif defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
+    osName = GetKernelName(true); // FIXME: for FreeBSD and NetBSD OS name is a kernel name
 #elif defined(TARGET_DARWIN_IOS)
     osName = "iOS";
 #elif defined(TARGET_DARWIN_OSX)
@@ -639,8 +639,8 @@ std::string CSysInfo::GetOsVersion(void)
   if (!osVersion.empty())
     return osVersion;
 
-#if defined(TARGET_WINDOWS) || defined(TARGET_FREEBSD)
-  osVersion = GetKernelVersion(); // FIXME: for Win32 and FreeBSD OS version is a kernel version
+#if defined(TARGET_WINDOWS) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
+  osVersion = GetKernelVersion(); // FIXME: for Win32, FreeBSD, and NetBSD OS version is a kernel version
 #elif defined(TARGET_DARWIN_IOS)
   osVersion = CDarwinUtils::GetIOSVersionString();
 #elif defined(TARGET_DARWIN_OSX)
@@ -736,7 +736,7 @@ std::string CSysInfo::GetOsPrettyNameWit
   }
   else
     osNameVer.append(" unknown");
-#elif defined(TARGET_FREEBSD) || defined(TARGET_DARWIN_IOS) || defined(TARGET_DARWIN_OSX)
+#elif defined(TARGET_FREEBSD) || defined(TARGET_NETBSD) || defined(TARGET_DARWIN_IOS) || defined(TARGET_DARWIN_OSX)
   osNameVer = GetOsName() + " " + GetOsVersion();
 #elif defined(TARGET_ANDROID)
   osNameVer = GetOsName() + " " + GetOsVersion() + " API level " +   StringUtils::Format("%d", CJNIBuild::SDK_INT);
@@ -992,6 +992,10 @@ const std::string& CSysInfo::GetKernelCp
       std::string machine(un.machine);
       if (machine.compare(0, 3, "arm", 3) == 0)
         kernelCpuFamily = "ARM";
+#if defined(TARGET_NETBSD)
+      else if (machine.compare(0, 6, "evbarm", 6) == 0)
+        kernelCpuFamily = "ARM";
+#endif
       else if (machine.compare(0, 4, "mips", 4) == 0)
         kernelCpuFamily = "MIPS";
       else if (machine.compare(0, 4, "i686", 4) == 0 || machine == "i386" || machine == "amd64" ||  machine.compare(0, 3, "x86", 3) == 0)
@@ -1251,6 +1255,8 @@ std::string CSysInfo::GetBuildTargetPlat
   return "iOS";
 #elif defined(TARGET_FREEBSD)
   return "FreeBSD";
+#elif defined(TARGET_NETBSD)
+  return "NetBSD";
 #elif defined(TARGET_ANDROID)
   return "Android";
 #elif defined(TARGET_LINUX)
@@ -1274,6 +1280,8 @@ std::string CSysInfo::GetBuildTargetPlat
   return XSTR_MACRO(__IPHONE_OS_VERSION_MIN_REQUIRED);
 #elif defined(TARGET_FREEBSD)
   return XSTR_MACRO(__FreeBSD_version);
+#elif defined(TARGET_NETBSD)
+  return XSTR_MACRO(__NetBSD_Version__);
 #elif defined(TARGET_ANDROID)
   return "API level " XSTR_MACRO(__ANDROID_API__);
 #elif defined(TARGET_LINUX)
@@ -1320,6 +1328,14 @@ std::string CSysInfo::GetBuildTargetPlat
     return StringUtils::Format("version %d.%d-STABLE", major, minor);
 
   return StringUtils::Format("version %d.%d-CURRENT", major, minor);
+#elif defined(TARGET_NETBSD)
+  static const int major = (__NetBSD_Version__ / 100000000) % 100;
+  static const int minor = (__NetBSD_Version__ / 1000000) % 100;
+  static const int patch = (__NetBSD_Version__ / 100) % 100;
+  if (patch != 0)
+    return StringUtils::Format("version %d.%d.%d", major, minor, patch);
+  else
+    return StringUtils::Format("version %d.%d", major, minor);
 #elif defined(TARGET_ANDROID)
   return "API level " XSTR_MACRO(__ANDROID_API__);
 #elif defined(TARGET_LINUX)
