$NetBSD: patch-m4_dolt.m4,v 1.2 2022/05/11 09:23:48 jperkin Exp $

Add NetBSD to dolt.m4. The fallback using libtool does not work
correctly.

--- m4/dolt.m4.orig	2017-11-24 15:29:17.000000000 +0000
+++ m4/dolt.m4
@@ -20,6 +20,7 @@ AS_IF([test x$GCC != xyes], [dolt_suppor
 
 AS_CASE([$host],
     [*-*-linux*|*-*-freebsd*], [pic_options='-fPIC'],
+    [*-*-netbsd*|*solaris*],   [pic_options='-fPIC -DPIC'],
     [*-apple-darwin*],         [pic_options='-fno-common'],
     [*mingw*|*nacl*],          [pic_options='']
     [*],                       [dolt_supported=no]
