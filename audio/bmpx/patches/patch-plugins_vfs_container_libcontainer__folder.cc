$NetBSD: patch-plugins_vfs_container_libcontainer__folder.cc,v 1.1 2012/11/16 20:05:35 joerg Exp $

--- plugins/vfs/container/libcontainer_folder.cc.orig	2012-11-16 13:51:32.000000000 +0000
+++ plugins/vfs/container/libcontainer_folder.cc
@@ -56,8 +56,8 @@ namespace Bmp
                 Bmp::URI u (uri);
                 if (u.get_protocol () != Bmp::URI::PROTOCOL_FILE) return false;
                 u.unescape ();
-                ustring uri ((u));
-                std::string path = filename_from_uri (uri);
+                ustring uri2 ((u));
+                std::string path = filename_from_uri (uri2);
                 return file_test (path, FILE_TEST_IS_DIR);
               }
             catch (...) { return false; }
