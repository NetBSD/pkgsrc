$NetBSD: patch-deps_openssl_openssl__no__asm.gypi,v 1.3 2019/02/24 12:18:55 rin Exp $

Support NetBSD/arm,aarch64,i386,amd64 (and hopefully other ILP32 archs)

XXX Change default to linux-elf instead of linux-x86_64 (from FreeBSD ports)

--- deps/openssl/openssl_no_asm.gypi.orig	2019-01-29 16:20:46.000000000 +0900
+++ deps/openssl/openssl_no_asm.gypi	2019-02-24 10:29:47.246812244 +0900
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
@@ -42,7 +48,7 @@
       'includes': ['config/archs/linux-x86_64/no-asm/openssl.gypi'],
     }, {
       # Other architectures don't use assembly
-      'includes': ['config/archs/linux-x86_64/no-asm/openssl.gypi'],
+      'includes': ['config/archs/linux-elf/no-asm/openssl.gypi'],
     }],
   ],
 }
