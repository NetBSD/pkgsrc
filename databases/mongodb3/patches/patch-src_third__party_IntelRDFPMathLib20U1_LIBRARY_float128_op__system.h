$NetBSD: patch-src_third__party_IntelRDFPMathLib20U1_LIBRARY_float128_op__system.h,v 1.1 2019/06/28 16:30:56 gdt Exp $

--- src/third_party/IntelRDFPMathLib20U1/LIBRARY/float128/op_system.h.orig	2017-04-20 21:43:42.000000000 +0000
+++ src/third_party/IntelRDFPMathLib20U1/LIBRARY/float128/op_system.h
@@ -44,6 +44,7 @@
 #       undef  win64 
 #       undef  darwin 
 #       undef  interix 
+#       undef  netbsd
 
 #	define dos 1
 #	define OP_SYSTEM dos
@@ -62,6 +63,7 @@
 #       undef   win64
 #       undef  darwin 
 #       undef  interix 
+#       undef  netbsd
 
 #	define vms 2
 #	define OP_SYSTEM vms
@@ -80,6 +82,7 @@
 #       undef  win64
 #       undef  darwin 
 #       undef  interix 
+#       undef  netbsd
 
 #	define wnt 3
 #	define OP_SYSTEM wnt
@@ -98,6 +101,7 @@
 #       undef  win64
 #       undef  darwin 
 #       undef  interix 
+#       undef  netbsd
 
 #	define linux 8
 #	define OP_SYSTEM linux
@@ -117,6 +121,7 @@
 #       undef  win64
 #       undef  darwin 
 #       undef  interix 
+#       undef  netbsd
 
 #	define osf 4
 #	define OP_SYSTEM osf
@@ -135,6 +140,7 @@
 #       undef  win64
 #       undef  darwin 
 #       undef  interix 
+#       undef  netbsd
 
 #	define hp_ux 5
 #	define OP_SYSTEM hp_ux
@@ -153,6 +159,7 @@
 #       undef  win64
 #       undef  darwin 
 #       undef  interix 
+#       undef  netbsd
 
 #	define unicos 6
 #	define OP_SYSTEM unicos
@@ -171,6 +178,7 @@
 #       undef  win64
 #       undef  darwin 
 #       undef  interix 
+#       undef  netbsd
 
 #	define ultrix 7
 #	define OP_SYSTEM ultrix
@@ -188,6 +196,7 @@
 #       undef  win64
 #       undef  darwin 
 #       undef  interix 
+#       undef  netbsd
 
 #       define win64 9
 #       define OP_SYSTEM win64
@@ -205,6 +214,7 @@
 #       undef  win64
 #       undef  darwin 
 #       undef  interix 
+#       undef  netbsd
 
 #       define darwin 10
 #       define OP_SYSTEM darwin
@@ -221,9 +231,27 @@
 #       undef  win64
 #       undef  darwin 
 #       undef  interix 
+#       undef  netbsd
 
 #       define interix 11
 #       define OP_SYSTEM interix
+
+#elif defined(__NetBSD__)
+#       undef  dos
+#       undef  vms
+#       undef  wnt
+#       undef  osf
+#       undef  hp_ux
+#       undef  linux
+#       undef  unicos
+#       undef  ultrix
+#       undef  win64
+#       undef  darwin 
+#       undef  interix 
+#       undef  netbsd
+
+#       define netbsd 12
+#       define OP_SYSTEM netbsd
 #else
 
 #	error Operating system must be specified.
@@ -235,6 +263,7 @@
 	OP_SYSTEM == linux || \
 	OP_SYSTEM == osf || \
 	OP_SYSTEM == ultrix || \
+	OP_SYSTEM == netbsd || \
 	OP_SYSTEM == unicos \
 )
 
