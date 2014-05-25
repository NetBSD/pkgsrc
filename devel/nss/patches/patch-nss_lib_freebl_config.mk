$NetBSD: patch-nss_lib_freebl_config.mk,v 1.1 2014/05/25 23:45:58 pho Exp $

Do not override the installation path of NSPR libraries.

--- nss/lib/freebl/config.mk.orig	2014-05-02 03:27:18.000000000 +0000
+++ nss/lib/freebl/config.mk
@@ -90,8 +90,4 @@ EXTRA_SHARED_LIBS += \
 endif
 endif
 
-ifeq ($(OS_ARCH), Darwin)
-EXTRA_SHARED_LIBS += -dylib_file @executable_path/libplc4.dylib:$(DIST)/lib/libplc4.dylib -dylib_file @executable_path/libplds4.dylib:$(DIST)/lib/libplds4.dylib
-endif
-
 endif
