$NetBSD: patch-deps_openssl_config_archs_linux-elf_asm_openssl-cl.gypi,v 1.1 2019/01/21 11:00:45 ryoon Exp $

--- deps/openssl/config/archs/linux-elf/asm/openssl-cl.gypi.orig	2018-09-20 07:28:30.000000000 +0000
+++ deps/openssl/config/archs/linux-elf/asm/openssl-cl.gypi
@@ -28,8 +28,16 @@
     'openssl_cflags_linux-elf': [
       '-Wall -O3 -pthread -DL_ENDIAN -fomit-frame-pointer',
     ],
-    'openssl_ex_libs_linux-elf': [
-      '-ldl -pthread',
+    'conditions': [
+      ['OS=="linux"', {
+        'openssl_ex_libs_linux-elf': [
+          '-ldl -pthread',
+        ],
+      }, {
+        'openssl_ex_libs_linux-elf': [
+          '',
+        ],
+      }],
     ],
     'openssl_cli_srcs_linux-elf': [
       'openssl/apps/app_rand.c',
