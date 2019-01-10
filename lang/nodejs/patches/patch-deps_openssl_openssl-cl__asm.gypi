$NetBSD: patch-deps_openssl_openssl-cl__asm.gypi,v 1.2 2019/01/10 13:02:41 ryoon Exp $

Add support for NetBSD.

--- deps/openssl/openssl-cl_asm.gypi.orig	2018-12-10 21:19:03.000000000 +0000
+++ deps/openssl/openssl-cl_asm.gypi
@@ -31,6 +31,10 @@
       'includes': ['config/archs/linux-elf/asm/openssl-cl.gypi'],
     }, 'target_arch=="x64" and OS=="freebsd"', {
       'includes': ['config/archs/BSD-x86_64/asm/openssl-cl.gypi'],
+    }, 'target_arch=="arm" and OS=="netbsd"', {
+      'includes': ['config/archs/linux-armv4/asm/openssl-cl.gypi'],
+    }, 'target_arch=="x64" and OS=="netbsd"', {
+      'includes': ['config/archs/BSD-x86_64/asm/openssl-cl.gypi'],
     }, 'target_arch=="x64" and OS=="mac"', {
       'includes': ['config/archs/darwin64-x86_64-cc/asm/openssl-cl.gypi'],
     }, 'target_arch=="x64" and OS=="solaris"', {
