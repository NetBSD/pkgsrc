$NetBSD: patch-deps_openssl_openssl__no__asm.gypi,v 1.2 2019/01/10 13:02:41 ryoon Exp $

Add support for NetBSD.

--- deps/openssl/openssl_no_asm.gypi.orig	2018-12-10 21:19:04.000000000 +0000
+++ deps/openssl/openssl_no_asm.gypi
@@ -32,6 +32,10 @@
       'includes': ['config/archs/linux-elf/no-asm/openssl.gypi'],
     }, 'target_arch=="x64" and OS=="freebsd"', {
       'includes': ['config/archs/BSD-x86_64/no-asm/openssl.gypi'],
+    }, 'target_arch=="arm" and OS=="netbsd"', {
+      'includes': ['config/archs/linux-armv4/no-asm/openssl.gypi'],
+    }, 'target_arch=="x64" and OS=="netbsd"', {
+      'includes': ['config/archs/BSD-x86_64/no-asm/openssl.gypi'],
     }, 'target_arch=="x64" and OS=="mac"', {
       'includes': ['config/archs/darwin64-x86_64-cc/no-asm/openssl.gypi'],
     }, 'target_arch=="x64" and OS=="solaris"', {
