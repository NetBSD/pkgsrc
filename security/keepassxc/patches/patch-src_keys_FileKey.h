$NetBSD: patch-src_keys_FileKey.h,v 1.1 2024/02/26 07:08:27 wiz Exp $

Fix build with botan 3.3.
https://github.com/keepassxreboot/keepassxc/commit/cc0530ba4671a7e2b6ac4a6c00cd097f4114fd22

--- src/keys/FileKey.h.orig	2024-02-26 07:05:43.610688903 +0000
+++ src/keys/FileKey.h
@@ -19,6 +19,7 @@
 #ifndef KEEPASSX_FILEKEY_H
 #define KEEPASSX_FILEKEY_H
 
+#include <botan/mem_ops.h>
 #include <botan/secmem.h>
 
 #include "keys/Key.h"
