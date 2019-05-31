$NetBSD: patch-deps_openssl_config_archs_linux-elf_asm_openssl-cl.gypi,v 1.2 2019/05/31 20:52:00 adam Exp $

--- deps/openssl/config/archs/linux-elf/asm/openssl-cl.gypi.orig	2019-05-28 21:32:15.000000000 +0000
+++ deps/openssl/config/archs/linux-elf/asm/openssl-cl.gypi
@@ -30,8 +30,16 @@
       '-pthread',
       '-Wall -O3 -fomit-frame-pointer',
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
       'openssl/apps/asn1pars.c',
