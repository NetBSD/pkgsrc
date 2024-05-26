$NetBSD: patch-src_solid_devices_backends_fstab_fstabhandling.cpp,v 1.1 2024/05/26 13:00:35 markd Exp $

Fix SunOS getmntent return value.

--- src/solid/devices/backends/fstab/fstabhandling.cpp.orig	2020-05-02 22:25:33.000000000 +0000
+++ src/solid/devices/backends/fstab/fstabhandling.cpp
@@ -82,7 +82,11 @@
 #define ENDMNTENT fclose
 #define STRUCT_MNTENT struct mnttab
 #define STRUCT_SETMNTENT FILE *
+#ifdef __sun
+#define GETMNTENT(file, var) (getmntent(file, &var) == 0)
+#else
 #define GETMNTENT(file, var) (getmntent(file, &var) == nullptr)
+#endif
 #define MOUNTPOINT(var) var.mnt_mountp
 #define MOUNTTYPE(var) var.mnt_fstype
 #define MOUNTOPTIONS(var) var.mnt_mntopts
