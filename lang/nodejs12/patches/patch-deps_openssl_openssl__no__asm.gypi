$NetBSD: patch-deps_openssl_openssl__no__asm.gypi,v 1.1 2019/12/09 20:05:40 adam Exp $

Support NetBSD/arm,aarch64,i386,amd64 (and hopefully other ILP32 archs)

--- deps/openssl/openssl_no_asm.gypi.orig	2019-11-19 08:29:07.000000000 +0000
+++ deps/openssl/openssl_no_asm.gypi
@@ -32,6 +32,12 @@
       'includes': ['config/archs/linux-elf/no-asm/openssl.gypi'],
     }, 'target_arch=="x64" and OS=="freebsd"', {
       'includes': ['config/archs/BSD-x86_64/no-asm/openssl.gypi'],
+    }, 'target_arch=="arm" and OS=="netbsd"', {
+      'includes': ['config/archs/linux-armv4/no-asm/openssl.gypi'],
+    }, 'target_arch=="arm64" and OS=="netbsd"', {
+      'includes': ['config/archs/linux-aarch64/no-asm/openssl.gypi'],
+    }, 'target_arch=="x64" and OS=="netbsd"', {
+      'includes': ['config/archs/BSD-x86_64/no-asm/openssl.gypi'],
     }, 'target_arch=="x64" and OS=="mac"', {
       'includes': ['config/archs/darwin64-x86_64-cc/no-asm/openssl.gypi'],
     }, 'target_arch=="x64" and OS=="solaris"', {
@@ -46,7 +52,7 @@
       'includes': ['config/archs/linux64-mips64/no-asm/openssl.gypi'],
     }, {
       # Other architectures don't use assembly
-      'includes': ['config/archs/linux-x86_64/no-asm/openssl.gypi'],
+      'includes': ['config/archs/linux-elf/no-asm/openssl.gypi'],
     }],
   ],
 }
