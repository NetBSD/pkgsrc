$NetBSD: patch-dlls_ntdll_file.c,v 1.1 2012/05/23 17:48:54 marino Exp $

--- dlls/ntdll/file.c.orig	2011-08-05 17:24:22.000000000 +0000
+++ dlls/ntdll/file.c
@@ -2256,7 +2256,9 @@ NTSTATUS WINAPI NtQueryAttributesFile( c
 }
 
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) \
+  || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__) \
+  || defined(__DragonFly__)
 /* helper for FILE_GetDeviceInfo to hide some platform differences in fstatfs */
 static inline void get_device_info_fstatfs( FILE_FS_DEVICE_INFORMATION *info, const char *fstypename,
                                             unsigned int flags )
@@ -2377,7 +2379,8 @@ static NTSTATUS get_device_info( int fd,
             info->DeviceType = FILE_DEVICE_DISK_FILE_SYSTEM;
             break;
         }
-#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__APPLE__)
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) \
+   || defined(__OpenBSD__) || defined(__APPLE__) || defined(__DragonFly__)
         struct statfs stfs;
 
         if (fstatfs( fd, &stfs ) < 0)
