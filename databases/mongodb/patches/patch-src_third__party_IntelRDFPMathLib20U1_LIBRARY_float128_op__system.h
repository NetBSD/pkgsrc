$NetBSD: patch-src_third__party_IntelRDFPMathLib20U1_LIBRARY_float128_op__system.h,v 1.3 2020/02/01 20:00:08 adam Exp $

Support NetBSD.

--- src/third_party/IntelRDFPMathLib20U1/LIBRARY/float128/op_system.h.orig	2019-12-04 23:29:59.000000000 +0000
+++ src/third_party/IntelRDFPMathLib20U1/LIBRARY/float128/op_system.h
@@ -45,6 +45,7 @@
 #       undef  darwin 
 #       undef  interix
 #       undef  emscripten
+#	undef  netbsd
 
 #	define dos 1
 #	define OP_SYSTEM dos
@@ -64,6 +65,7 @@
 #       undef  darwin 
 #       undef  interix 
 #       undef  emscripten
+#	undef  netbsd
 
 #	define vms 2
 #	define OP_SYSTEM vms
@@ -83,6 +85,7 @@
 #       undef  darwin 
 #       undef  interix 
 #       undef  emscripten
+#	undef  netbsd
 
 #	define wnt 3
 #	define OP_SYSTEM wnt
@@ -102,6 +105,7 @@
 #       undef  darwin 
 #       undef  interix 
 #       undef  emscripten
+#	undef  netbsd
 
 #	define linux 8
 #	define OP_SYSTEM linux
@@ -122,6 +126,7 @@
 #       undef  darwin 
 #       undef  interix 
 #       undef  emscripten
+#	undef  netbsd
 
 #	define osf 4
 #	define OP_SYSTEM osf
@@ -141,6 +146,7 @@
 #       undef  darwin 
 #       undef  interix 
 #       undef  emscripten
+#	undef  netbsd
 
 #	define hp_ux 5
 #	define OP_SYSTEM hp_ux
@@ -160,6 +166,7 @@
 #       undef  darwin 
 #       undef  interix 
 #       undef  emscripten
+#	undef  netbsd
 
 #	define unicos 6
 #	define OP_SYSTEM unicos
@@ -179,6 +186,7 @@
 #       undef  darwin 
 #       undef  interix 
 #       undef  emscripten
+#	undef  netbsd
 
 #	define ultrix 7
 #	define OP_SYSTEM ultrix
@@ -197,6 +205,7 @@
 #       undef  darwin 
 #       undef  interix 
 #       undef  emscripten
+#	undef  netbsd
 
 #       define win64 9
 #       define OP_SYSTEM win64
@@ -215,6 +224,7 @@
 #       undef  darwin 
 #       undef  interix 
 #       undef  emscripten
+#	undef  netbsd
 
 #       define darwin 10
 #       define OP_SYSTEM darwin
@@ -232,6 +242,7 @@
 #       undef  darwin 
 #       undef  interix 
 #       undef  emscripten
+#	undef  netbsd
 
 #       define interix 11
 #       define OP_SYSTEM interix
@@ -250,10 +261,29 @@
 #       undef  darwin 
 #       undef  interix 
 #       undef  emscripten
+#	undef  netbsd
 
 #	define emscripten 12
 #	define OP_SYSTEM emscripten
 
+#elif defined(__NetBSD__)
+#	undef  dos
+#	undef  vms
+#	undef  wnt
+#	undef  osf
+#	undef  hp_ux
+#	undef  linux
+#	undef  unicos
+#	undef  ultrix
+#	undef  win64
+#	undef  darwin 
+#	undef  interix 
+#	undef  emscripten
+#	undef  netbsd
+
+#	define netbsd 12
+#	define OP_SYSTEM netbsd
+
 #else
 
 #	error Operating system must be specified.
@@ -266,6 +296,7 @@
 	OP_SYSTEM == osf || \
 	OP_SYSTEM == ultrix || \
 	OP_SYSTEM == unicos || \
+	OP_SYSTEM == netbsd || \
 	OP_SYSTEM == emscripten \
 )
 
