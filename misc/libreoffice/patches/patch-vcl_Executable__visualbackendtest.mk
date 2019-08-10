$NetBSD: patch-vcl_Executable__visualbackendtest.mk,v 1.3 2019/08/10 11:41:29 ryoon Exp $

* Fix build on non-Linux Unix-like OSes

--- vcl/Executable_visualbackendtest.mk.orig	2019-08-06 17:26:35.000000000 +0000
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
     -lX11 \
 ))
 
