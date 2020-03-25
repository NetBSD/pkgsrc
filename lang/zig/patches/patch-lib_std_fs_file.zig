$NetBSD: patch-lib_std_fs_file.zig,v 1.1 2020/03/25 22:27:20 nia Exp $

Portability.

--- lib/std/fs/file.zig.orig	2019-09-30 15:40:00.000000000 +0000
+++ lib/std/fs/file.zig
@@ -41,7 +41,7 @@ pub const File = struct {
             const path_w = try windows.cStrToPrefixedFileW(path);
             return openReadW(&path_w);
         }
-        const flags = os.O_LARGEFILE | os.O_RDONLY;
+        const flags = os.O_RDONLY;
         const fd = try os.openC(path, flags, 0);
         return openHandle(fd);
     }
@@ -83,7 +83,7 @@ pub const File = struct {
             const path_w = try windows.cStrToPrefixedFileW(path);
             return openWriteModeW(&path_w, file_mode);
         }
-        const flags = os.O_LARGEFILE | os.O_WRONLY | os.O_CREAT | os.O_CLOEXEC | os.O_TRUNC;
+        const flags = os.O_WRONLY | os.O_CREAT | os.O_CLOEXEC | os.O_TRUNC;
         const fd = try os.openC(path, flags, file_mode);
         return openHandle(fd);
     }
@@ -119,7 +119,7 @@ pub const File = struct {
             const path_w = try windows.cStrToPrefixedFileW(path);
             return openWriteNoClobberW(&path_w, file_mode);
         }
-        const flags = os.O_LARGEFILE | os.O_WRONLY | os.O_CREAT | os.O_CLOEXEC | os.O_EXCL;
+        const flags = os.O_WRONLY | os.O_CREAT | os.O_CLOEXEC | os.O_EXCL;
         const fd = try os.openC(path, flags, file_mode);
         return openHandle(fd);
     }
