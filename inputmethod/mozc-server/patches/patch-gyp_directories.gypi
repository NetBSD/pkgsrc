$NetBSD: patch-gyp_directories.gypi,v 1.2 2021/02/15 14:50:23 ryoon Exp $

--- gyp/directories.gypi.orig	2021-02-15 05:04:33.000000000 +0000
+++ gyp/directories.gypi
@@ -43,7 +43,7 @@
 
     # server_dir represents the directory where mozc_server is
     # installed. This option is only for Linux.
-    'server_dir%': '/usr/lib/mozc',
+    'server_dir%': '@PREFIX@/libexec',
 
     # Represents the directory where the source code of protobuf is
     # extracted. This value is ignored when 'use_libprotobuf' is 1.
