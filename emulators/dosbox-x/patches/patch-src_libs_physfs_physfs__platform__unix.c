$NetBSD: patch-src_libs_physfs_physfs__platform__unix.c,v 1.1 2021/08/10 11:04:15 nia Exp $

NetBSD support. ideally this should use devel/physfs...

--- src/libs/physfs/physfs_platform_unix.c.orig	2021-08-01 07:45:55.000000000 +0000
+++ src/libs/physfs/physfs_platform_unix.c
@@ -53,10 +53,14 @@
 #include <sys/mnttab.h>
 #endif
 
-#ifdef PHYSFS_PLATFORM_FREEBSD
+#if defined(PHYSFS_PLATFORM_FREEBSD) || defined(__NetBSD__)
 #include <sys/sysctl.h>
 #endif
 
+#ifdef __NetBSD__
+#include <sys/statvfs.h>
+#define statfs statvfs
+#endif
 
 #include "physfs_internal.h"
 
@@ -261,6 +265,14 @@ char *__PHYSFS_platformCalcBaseDir(const
         if (sysctl(mib, 4, fullpath, &buflen, NULL, 0) != -1)
             retval = __PHYSFS_strdup(fullpath);
     }
+    #elif defined(__NetBSD__)
+    {
+        char fullpath[PATH_MAX];
+        size_t buflen = sizeof (fullpath);
+        int mib[4] = { CTL_KERN, KERN_PROC_ARGS, -1, KERN_PROC_PATHNAME };
+        if (sysctl(mib, 4, fullpath, &buflen, NULL, 0) != -1)
+            retval = __PHYSFS_strdup(fullpath);
+    }
     #elif defined(PHYSFS_PLATFORM_SOLARIS)
     {
         const char *path = getexecname();
