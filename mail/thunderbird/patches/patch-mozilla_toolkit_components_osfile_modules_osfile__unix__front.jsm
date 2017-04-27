$NetBSD: patch-mozilla_toolkit_components_osfile_modules_osfile__unix__front.jsm,v 1.4 2017/04/27 13:32:41 ryoon Exp $

--- mozilla/toolkit/components/osfile/modules/osfile_unix_front.jsm.orig	2017-04-14 04:53:28.000000000 +0000
+++ mozilla/toolkit/components/osfile/modules/osfile_unix_front.jsm
@@ -399,7 +399,7 @@
        throw_on_negative("statvfs",  (UnixFile.statvfs || UnixFile.statfs)(sourcePath, fileSystemInfoPtr));
 
        let bytes = new Type.uint64_t.implementation(
-                        fileSystemInfo.f_bsize * fileSystemInfo.f_bavail);
+                        fileSystemInfo.f_frsize * fileSystemInfo.f_bavail);
 
        return bytes.value;
      };
