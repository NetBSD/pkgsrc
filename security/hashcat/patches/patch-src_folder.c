$NetBSD: patch-src_folder.c,v 1.3 2025/08/08 07:24:00 adam Exp $

BSD support https://github.com/hashcat/hashcat/pull/4392

--- src/folder.c.orig	2025-08-01 21:03:55.000000000 +0000
+++ src/folder.c
@@ -13,7 +13,11 @@
 
 #if defined (__APPLE__)
 #include "event.h"
-#elif defined (__FreeBSD__) || defined (__NetBSD__)
+#elif defined (__OpenBSD__)
+#define _OPENBSD_SOURCE
+#include <stdlib.h>
+#include <sys/sysctl.h>
+#elif defined (__FreeBSD__) || defined (__NetBSD__) || defined (__DragonFly__)
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #endif
@@ -46,7 +50,7 @@ static int get_exec_path (char *exec_pat
 
   const size_t len = strlen (exec_path);
 
-  #elif defined (__FreeBSD__)
+  #elif defined (__FreeBSD__) || defined (__DragonFly__)
 
   int mib[4];
 
@@ -76,6 +80,41 @@ static int get_exec_path (char *exec_pat
 
   const size_t len = strlen (exec_path);
 
+  #elif defined (__OpenBSD__)
+
+  int mib[4];
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC_ARGS;
+  mib[2] = getpid ();
+  mib[3] = KERN_PROC_ARGV;
+
+  size_t size = 0;
+
+  if (sysctl (mib, 4, NULL, &size, NULL, 0) == -1) return -1;
+
+  char **argv = hcmalloc (size);
+
+  if (!argv) return -1;
+
+  if (sysctl (mib, 4, argv, &size, NULL, 0) == -1)
+  {
+    free (argv);
+
+    return -1;
+  }
+
+  if (argv[0])
+  {
+    strncpy (exec_path, argv[0], exec_path_sz - 1);
+
+    exec_path[exec_path_sz - 1] = '\0';
+  }
+
+  free (argv);
+
+  const size_t len = strlen (exec_path);
+
   #else
   #error Your Operating System is not supported or detected
   #endif
