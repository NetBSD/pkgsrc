$NetBSD: patch-nss_lib_freebl_config.mk,v 1.2 2017/09/26 10:59:40 ryoon Exp $

Do not override the installation path of NSPR libraries.

--- nss/lib/freebl/config.mk.orig	2017-09-20 06:47:27.000000000 +0000
+++ nss/lib/freebl/config.mk
@@ -96,7 +96,6 @@ endif
 
 ifeq ($(OS_ARCH), Darwin)
 CFLAGS += -std=gnu99
-EXTRA_SHARED_LIBS += -dylib_file @executable_path/libplc4.dylib:$(DIST)/lib/libplc4.dylib -dylib_file @executable_path/libplds4.dylib:$(DIST)/lib/libplds4.dylib
 endif
 
 endif
