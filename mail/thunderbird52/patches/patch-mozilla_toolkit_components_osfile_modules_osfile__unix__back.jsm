$NetBSD: patch-mozilla_toolkit_components_osfile_modules_osfile__unix__back.jsm,v 1.1 2018/12/16 08:29:48 ryoon Exp $

--- mozilla/toolkit/components/osfile/modules/osfile_unix_back.jsm.orig	2017-04-14 04:53:29.000000000 +0000
+++ mozilla/toolkit/components/osfile/modules/osfile_unix_back.jsm
@@ -228,8 +228,8 @@
          let statvfs = new SharedAll.HollowStructure("statvfs",
            Const.OSFILE_SIZEOF_STATVFS);
 
-         statvfs.add_field_at(Const.OSFILE_OFFSETOF_STATVFS_F_BSIZE,
-                        "f_bsize", Type.unsigned_long.implementation);
+         statvfs.add_field_at(Const.OSFILE_OFFSETOF_STATVFS_F_FRSIZE,
+                        "f_frsize", Type.unsigned_long.implementation);
          statvfs.add_field_at(Const.OSFILE_OFFSETOF_STATVFS_F_BAVAIL,
                         "f_bavail", Type.fsblkcnt_t.implementation);
 
