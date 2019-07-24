$NetBSD: patch-src_file.cc,v 1.1 2019/07/24 17:01:02 nia Exp $

Allow KAK_BIN_PATH to be used as a fallback for finding the executable
path on more platforms.

--- src/file.cc.orig	2019-07-01 12:07:29.000000000 +0000
+++ src/file.cc
@@ -641,10 +641,8 @@ String get_kak_binary_path()
     kak_assert(res != -1);
     buffer[res] = '\0';
     return buffer;
-#elif defined(__OpenBSD__)
-    return KAK_BIN_PATH;
 #else
-# error "finding executable path is not implemented on this platform"
+    return KAK_BIN_PATH;
 #endif
 }
 
