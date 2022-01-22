$NetBSD: patch-vmhgfs-fuse_config.c,v 1.3 2022/01/22 18:52:44 pho Exp $

* The original SysCompatCheck() only works on Linux.
* librefuse didn't support the old style -ho option. Fixed in HEAD.

--- vmhgfs-fuse/config.c.orig	2018-06-23 10:03:28.000000000 +0000
+++ vmhgfs-fuse/config.c
@@ -23,6 +23,7 @@
 
 #include "module.h"
 #include <sys/utsname.h>
+#include <sys/stat.h>
 
 #ifdef VMX86_DEVEL
 int LOGLEVEL_THRESHOLD = 4;
@@ -136,6 +137,7 @@ Usage(char *prog_name)  // IN
 #define PROC_FILESYSTEMS       "/proc/filesystems"
 #define FUSER_KERNEL_FS        "fuse"
 
+#if defined(__linux__)
 /*
  *----------------------------------------------------------------------
  *
@@ -173,8 +175,9 @@ SysCompatFusermountCheck(void)  // IN:
 
    return fusermountExists;
 }
+#endif
 
-
+#if defined(__linux__)
 /*
  *----------------------------------------------------------------------
  *
@@ -253,8 +256,9 @@ exit:
    free(modulesDep);
    return installedFuse;
 }
+#endif
 
-
+#if defined(__linux__)
 /*
  *----------------------------------------------------------------------
  *
@@ -307,7 +311,7 @@ exit:
    }
    return registeredFuse;
 }
-
+#endif
 
 /*
  *----------------------------------------------------------------------
@@ -328,6 +332,7 @@ exit:
  */
 static HgfsSystemCompatibility
 SysCompatCheck(char *prog_name)  // IN
+#if defined(__linux__)
 {
    struct utsname buf;
    HgfsSystemCompatibility sysCompat = HGFS_SYSCOMPAT_OS_NOT_SUPPORTED;
@@ -381,6 +386,17 @@ exit:
            HgfsSystemCompatibilityMsg[sysCompat]);
    return sysCompat;
 }
+#elif defined(__NetBSD__)
+{
+   HgfsSystemCompatibility sysCompat = HGFS_SYSCOMPAT_FUSE_ENABLED;
+   struct stat st;
+
+   if (stat("/dev/puffs", &st) == -1)
+      sysCompat = HGFS_SYSCOMPAT_OS_NO_FUSE;
+
+   return sysCompat;
+}
+#endif
 
 
 /*
@@ -444,7 +460,13 @@ vmhgfsOptProc(void *data,               
 
    case KEY_HELP:
       Usage(outargs->argv[0]);
+#if defined(__NetBSD__) && FUSE_H_ < 20211204
+      fuse_opt_add_arg(outargs, "--help");
+      free(outargs->argv[0]);
+      outargs->argv[0] = strdup("");
+#else
       fuse_opt_add_arg(outargs, "-ho");
+#endif
       fuse_main(outargs->argc, outargs->argv, NULL, NULL);
       exit(1);
 
