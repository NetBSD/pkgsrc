$NetBSD: patch-vcl_Executable__visualbackendtest.mk,v 1.1 2017/02/04 01:48:00 ryoon Exp $

* Fix build on non-Linux Unix-like OSes

--- vcl/Executable_visualbackendtest.mk.orig	2017-02-02 22:22:26.593859446 +0000
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
     -lGL \
     -lX11 \
