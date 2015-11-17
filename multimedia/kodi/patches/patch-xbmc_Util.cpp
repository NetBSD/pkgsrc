$NetBSD: patch-xbmc_Util.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/Util.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/Util.cpp
@@ -26,7 +26,7 @@
 #include <mach-o/dyld.h>
 #endif
 
-#if defined(TARGET_FREEBSD)
+#if defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #endif
@@ -1663,7 +1663,7 @@ std::string CUtil::ResolveExecutablePath
 
   CDarwinUtils::GetExecutablePath(given_path, &path_size);
   strExecutablePath = given_path;
-#elif defined(TARGET_FREEBSD)                                                                                                                                                                   
+#elif defined(TARGET_FREEBSD)
   char buf[PATH_MAX];
   size_t buflen;
   int mib[4];
@@ -1678,6 +1678,21 @@ std::string CUtil::ResolveExecutablePath
     strExecutablePath = "";
   else
     strExecutablePath = buf;
+#elif defined(TARGET_NETBSD)
+  char buf[PATH_MAX];
+  size_t buflen;
+  int mib[4];
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC_ARGS;
+  mib[2] = getpid();
+  mib[3] = KERN_PROC_PATHNAME;
+
+  buflen = sizeof(buf) - 1;
+  if(sysctl(mib, 4, buf, &buflen, NULL, 0) < 0)
+    strExecutablePath = "";
+  else
+    strExecutablePath = buf;
 #else
   /* Get our PID and build the name of the link in /proc */
   pid_t pid = getpid();
