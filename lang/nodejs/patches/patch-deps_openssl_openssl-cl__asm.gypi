$NetBSD: patch-deps_openssl_openssl-cl__asm.gypi,v 1.3 2019/02/24 12:18:55 rin Exp $

Support NetBSD/arm,aarch64,i386,amd64 (and hopefully other ILP32 archs)

XXX Change default to linux-elf instead of linux-x86_64 (from FreeBSD ports)

--- deps/openssl/openssl-cl_asm.gypi.orig	2019-01-29 16:20:45.000000000 +0900
+++ deps/openssl/openssl-cl_asm.gypi	2019-02-24 10:28:36.290301337 +0900
@@ -31,6 +31,12 @@
       'includes': ['config/archs/linux-elf/asm/openssl-cl.gypi'],
     }, 'target_arch=="x64" and OS=="freebsd"', {
       'includes': ['config/archs/BSD-x86_64/asm/openssl-cl.gypi'],
+    }, 'target_arch=="arm" and OS=="netbsd"', {
+      'includes': ['config/archs/linux-armv4/asm/openssl-cl.gypi'],
+    }, 'target_arch=="arm64" and OS=="netbsd"', {
+      'includes': ['config/archs/linux-aarch64/asm/openssl-cl.gypi'],
+    }, 'target_arch=="x64" and OS=="netbsd"', {
+      'includes': ['config/archs/BSD-x86_64/asm/openssl-cl.gypi'],
     }, 'target_arch=="x64" and OS=="mac"', {
       'includes': ['config/archs/darwin64-x86_64-cc/asm/openssl-cl.gypi'],
     }, 'target_arch=="x64" and OS=="solaris"', {
@@ -41,7 +47,7 @@
       'includes': ['config/archs/linux-x86_64/asm/openssl-cl.gypi'],
     }, {
       # Other architectures don't use assembly
-      'includes': ['config/archs/linux-x86_64/asm/openssl-cl.gypi'],
+      'includes': ['config/archs/linux-elf/asm/openssl-cl.gypi'],
     }],
   ],
 }
