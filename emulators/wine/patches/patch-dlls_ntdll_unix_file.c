$NetBSD: patch-dlls_ntdll_unix_file.c,v 1.1 2024/11/01 14:10:47 triaxx Exp $

Add a conditional declaration of struct statvfs to support NetBSD.

--- dlls/ntdll/unix/file.c.orig	2024-01-16 20:55:47.000000000 +0000
+++ dlls/ntdll/unix/file.c
@@ -6814,7 +6814,11 @@ NTSTATUS WINAPI NtQueryVolumeInformation
         if (!get_mountmgr_fs_info( handle, fd, &drive, sizeof(drive) )) fs_type = drive.fs_type;
         else
         {
+#if defined(__NetBSD__)
+            struct statvfs stfs;
+#else
             struct statfs stfs;
+#endif
 
             if (!fstatfs( fd, &stfs ))
             {
@@ -6831,7 +6835,7 @@ NTSTATUS WINAPI NtQueryVolumeInformation
                     fs_type = MOUNTMGR_FS_TYPE_FAT32;
                     break;
                 }
-#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__APPLE__)
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__APPLE__)
                 if (!strcmp( stfs.f_fstypename, "cd9660" ))
                     fs_type = MOUNTMGR_FS_TYPE_ISO9660;
                 else if (!strcmp( stfs.f_fstypename, "udf" ))
