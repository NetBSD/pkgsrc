$NetBSD: patch-deps_openssl_openssl__asm.gypi,v 1.1 2018/05/03 21:19:16 fhajny Exp $

Add support for NetBSD.

--- deps/openssl/openssl_asm.gypi.orig	2018-04-24 14:41:22.000000000 +0000
+++ deps/openssl/openssl_asm.gypi
@@ -46,6 +46,8 @@
       'includes': ['config/archs/linux-elf/asm/openssl.gypi'],
     }, 'target_arch=="x64" and OS=="freebsd"', {
       'includes': ['config/archs/BSD-x86_64/asm/openssl.gypi'],
+    }, 'target_arch=="x64" and OS=="netbsd"', {
+      'includes': ['config/archs/BSD-x86_64/asm/openssl.gypi'],
     }, 'target_arch=="x64" and OS=="mac"', {
       'includes': ['config/archs/darwin64-x86_64-cc/asm/openssl.gypi'],
     }, 'target_arch=="x64" and OS=="solaris"', {
