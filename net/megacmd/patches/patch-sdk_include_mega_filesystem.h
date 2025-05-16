$NetBSD: patch-sdk_include_mega_filesystem.h,v 1.1 2025/05/16 19:43:58 wiz Exp $

* Add BSD supported filesystems

--- sdk/include/mega/filesystem.h.orig	2025-04-02 09:16:59.000000000 +0200
+++ sdk/include/mega/filesystem.h
@@ -51,6 +51,10 @@ enum FileSystemType
     FS_SMB = 12,
     FS_SMB2 = 13,
     FS_LIFS = 14,
+    FS_FFS = 15,
+    FS_HAMMER = 16,
+    FS_UFS = 17,
+    FS_ZFS = 18,
 };
 
 typedef void (*asyncfscallback)(void *);
@@ -233,11 +237,13 @@ class MEGA_API LocalPath
     friend class ScopedSyncPathRestore;
     friend class WinFileSystemAccess;
     friend class PosixFileSystemAccess;
+    friend class FallbackFileSystemAccess;
     friend struct WinDirAccess;
     friend struct WinDirNotify;
     friend class LinuxDirNotify;
     friend class MacDirNotify;
     friend class PosixDirNotify;
+    friend class FallbackDirNotify;
     friend class WinFileAccess;
     friend class PosixFileAccess;
     friend void RemoveHiddenFileAttribute(LocalPath& path);
