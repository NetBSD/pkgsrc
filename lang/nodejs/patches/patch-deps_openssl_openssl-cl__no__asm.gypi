$NetBSD: patch-deps_openssl_openssl-cl__no__asm.gypi,v 1.2 2019/01/10 13:02:41 ryoon Exp $

Add support for NetBSD.

--- deps/openssl/openssl-cl_no_asm.gypi.orig	2018-12-10 21:19:03.000000000 +0000
+++ deps/openssl/openssl-cl_no_asm.gypi
@@ -31,6 +31,10 @@
       'includes': ['config/archs/linux-elf/no-asm/openssl-cl.gypi'],
     }, 'target_arch=="x64" and OS=="freebsd"', {
       'includes': ['config/archs/BSD-x86_64/no-asm/openssl-cl.gypi'],
+    }, 'target_arch=="x64" and OS=="netbsd"', {
+      'includes': ['config/archs/BSD-x86_64/no-asm/openssl-cl.gypi'],
+    }, 'target_arch=="arm" and OS=="netbsd"', {
+      'includes': ['config/archs/linux-armv4/no-asm/openssl-cl.gypi'],
     }, 'target_arch=="x64" and OS=="mac"', {
       'includes': ['config/archs/darwin64-x86_64-cc/no-asm/openssl-cl.gypi'],
     }, 'target_arch=="x64" and OS=="solaris"', {
