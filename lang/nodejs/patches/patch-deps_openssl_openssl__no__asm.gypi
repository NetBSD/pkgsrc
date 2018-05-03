$NetBSD: patch-deps_openssl_openssl__no__asm.gypi,v 1.1 2018/05/03 21:19:16 fhajny Exp $

Add support for NetBSD.

--- deps/openssl/openssl_no_asm.gypi.orig	2018-04-24 14:41:22.000000000 +0000
+++ deps/openssl/openssl_no_asm.gypi
@@ -32,6 +32,8 @@
       'includes': ['config/archs/linux-elf/no-asm/openssl.gypi'],
     }, 'target_arch=="x64" and OS=="freebsd"', {
       'includes': ['config/archs/BSD-x86_64/no-asm/openssl.gypi'],
+    }, 'target_arch=="x64" and OS=="netbsd"', {
+      'includes': ['config/archs/BSD-x86_64/no-asm/openssl.gypi'],
     }, 'target_arch=="x64" and OS=="mac"', {
       'includes': ['config/archs/darwin64-x86_64-cc/no-asm/openssl.gypi'],
     }, 'target_arch=="x64" and OS=="solaris"', {
