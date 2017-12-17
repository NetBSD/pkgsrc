$NetBSD: patch-gyp_directories.gypi,v 1.1 2017/12/17 14:15:43 tsutsui Exp $

* use ${PREFIX} paths

--- gyp/directories.gypi.orig	2017-11-02 13:32:47.000000000 +0000
+++ gyp/directories.gypi
@@ -42,7 +42,7 @@
 
     # server_dir represents the directory where mozc_server is
     # installed. This option is only for Linux.
-    'server_dir%': '/usr/lib/mozc',
+    'server_dir%': '@PREFIX@/libexec',
 
     # Represents the directory where the source code of protobuf is
     # extracted. This value is ignored when 'use_libprotobuf' is 1.
@@ -85,7 +85,7 @@
         # Win / Mac / Linux:
         #     this file path is directory used by binaries without copying.
         'zinnia_model_file%':
-        '/usr/share/tegaki/models/zinnia/handwriting-ja.model',
+        '@PREFIX@/share/tegaki/models/zinnia/handwriting-ja.model',
       }],
     ],
   },
