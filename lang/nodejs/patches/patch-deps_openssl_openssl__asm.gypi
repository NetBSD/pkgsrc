$NetBSD: patch-deps_openssl_openssl__asm.gypi,v 1.3 2019/02/24 12:18:55 rin Exp $

Support NetBSD/arm,aarch64,i386,amd64 (and hopefully other ILP32 archs)

XXX Change default to linux-elf instead of linux-x86_64 (from FreeBSD ports)

--- deps/openssl/openssl_asm.gypi.orig	2019-01-29 16:20:46.000000000 +0900
+++ deps/openssl/openssl_asm.gypi	2019-02-24 12:11:23.696088048 +0900
@@ -46,6 +46,12 @@
       'includes': ['config/archs/linux-elf/asm/openssl.gypi'],
     }, 'target_arch=="x64" and OS=="freebsd"', {
       'includes': ['config/archs/BSD-x86_64/asm/openssl.gypi'],
+    }, 'target_arch=="arm" and OS=="netbsd"', {
+      'includes': ['config/archs/linux-armv4/asm/openssl.gypi'],
+    }, 'target_arch=="arm64" and OS=="netbsd"', {
+      'includes': ['config/archs/linux-aarch64/asm/openssl.gypi'],
+    }, 'target_arch=="x64" and OS=="netbsd"', {
+      'includes': ['config/archs/BSD-x86_64/asm/openssl.gypi'],
     }, 'target_arch=="x64" and OS=="mac"', {
       'includes': ['config/archs/darwin64-x86_64-cc/asm/openssl.gypi'],
     }, 'target_arch=="x64" and OS=="solaris"', {
@@ -75,7 +81,7 @@
       'includes': ['config/archs/linux-x86_64/asm/openssl.gypi'],
     }, {
       # Other architectures don't use assembly
-      'includes': ['config/archs/linux-x86_64/asm/openssl.gypi'],
+      'includes': ['config/archs/linux-elf/asm/openssl.gypi'],
     }],
   ],
 }
