$NetBSD: patch-src_folder.c,v 1.1 2022/01/10 02:30:23 khorben Exp $

Fix the build for NetBSD

--- src/folder.c.orig	2021-11-21 15:39:01.000000000 +0000
+++ src/folder.c
@@ -13,6 +13,9 @@
 
 #if defined (__APPLE__)
 #include "event.h"
+#elif defined (__FreeBSD__) || defined (__NetBSD__)
+#include <sys/param.h>
+#include <sys/sysctl.h>
 #endif
 
 static int get_exec_path (char *exec_path, const size_t exec_path_sz)
@@ -45,8 +48,6 @@ static int get_exec_path (char *exec_pat
 
   #elif defined (__FreeBSD__)
 
-  #include <sys/sysctl.h>
-
   int mib[4];
 
   mib[0] = CTL_KERN;
@@ -60,6 +61,21 @@ static int get_exec_path (char *exec_pat
 
   const size_t len = strlen (exec_path);
 
+  #elif defined (__NetBSD__)
+
+  int mib[4];
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC_ARGS;
+  mib[2] = getpid();
+  mib[3] = KERN_PROC_PATHNAME;
+
+  size_t size = exec_path_sz;
+
+  sysctl (mib, 4, exec_path, &size, NULL, 0);
+
+  const size_t len = strlen (exec_path);
+
   #else
   #error Your Operating System is not supported or detected
   #endif
