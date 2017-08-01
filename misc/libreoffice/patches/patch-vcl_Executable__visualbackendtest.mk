$NetBSD: patch-vcl_Executable__visualbackendtest.mk,v 1.2 2017/08/01 11:57:37 ryoon Exp $

* Fix build on non-Linux Unix-like OSes

--- vcl/Executable_visualbackendtest.mk.orig	2017-07-25 20:26:39.000000000 +0000
+++ vcl/Executable_visualbackendtest.mk
@@ -41,10 +41,10 @@ $(eval $(call gb_Executable_use_static_l
     vclmain \
 ))
 
-ifeq ($(OS),LINUX)
+ifeq ($(OS), $(filter LINUX %BSD SOLARIS, $(OS)))
 $(eval $(call gb_Executable_add_libs,visualbackendtest,\
 	-lm \
-	-ldl \
+	$(DLOPEN_LIBS) \
 	-lpthread \
     -lX11 \
 ))
