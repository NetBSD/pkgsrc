$NetBSD: patch-deps_openssl_openssl-cl__asm.gypi,v 1.4 2019/12/09 20:03:51 adam Exp $

Support NetBSD/arm,aarch64,i386,amd64 (and hopefully other ILP32 archs)

XXX Change default to linux-elf instead of linux-x86_64 (from FreeBSD ports)

--- deps/openssl/openssl-cl_asm.gypi.orig	2019-11-19 08:29:07.000000000 +0000
+++ deps/openssl/openssl-cl_asm.gypi
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
@@ -43,7 +49,7 @@
       'includes': ['config/archs/linux64-mips64/asm/openssl-cl.gypi'],
     },{
       # Other architectures don't use assembly
-      'includes': ['config/archs/linux-x86_64/asm/openssl-cl.gypi'],
+      'includes': ['config/archs/linux-elf/asm/openssl-cl.gypi'],
     }],
   ],
 }
