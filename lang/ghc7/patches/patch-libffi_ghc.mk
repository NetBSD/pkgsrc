$NetBSD: patch-libffi_ghc.mk,v 1.1.2.2 2016/05/23 04:57:18 bsiegert Exp $

--- libffi/ghc.mk.orig	2015-09-22 19:10:58.000000000 +0000
+++ libffi/ghc.mk
@@ -31,7 +31,7 @@ libffi_STAMP_INSTALL   = $(libffi_STAMP_
 libffi_EnableShared    = no
 endif
 
-libffi_STATIC_LIB  = libffi/build/inst/lib/libffi.a
+libffi_STATIC_LIB  = libffi/build/inst${ghclibdir}/libffi.a
 libffi_HEADERS     = rts/dist/build/ffi.h \
                      rts/dist/build/ffitarget.h
 
@@ -85,8 +85,8 @@ $(libffi_STAMP_CONFIGURE): $(TOUCH_DEP)
         CFLAGS="$(SRC_CC_OPTS) $(CONF_CC_OPTS_STAGE1) -w" \
         LDFLAGS="$(SRC_LD_OPTS) $(CONF_GCC_LINKER_OPTS_STAGE1) -w" \
         "$(SHELL)" configure \
-	          --prefix=$(TOP)/libffi/build/inst \
-	          --libdir=$(TOP)/libffi/build/inst/lib \
+	          --prefix=${prefix} \
+	          --libdir=${ghclibdir} \
 	          --enable-static=yes \
 	          --enable-shared=$(libffi_EnableShared) \
 	          --host=$(TargetPlatformFull)
@@ -103,14 +103,14 @@ $(libffi_STAMP_BUILD): $(libffi_STAMP_CO
 	"$(TOUCH_CMD)" $@
 
 $(libffi_STAMP_INSTALL): $(libffi_STAMP_BUILD) $(TOUCH_DEP)
-	$(MAKE) -C libffi/build MAKEFLAGS= install
+	$(MAKE) -C libffi/build MAKEFLAGS= install DESTDIR=$(TOP)/libffi/build/inst
 	"$(TOUCH_CMD)" $@
 
 $(libffi_STATIC_LIB): $(libffi_STAMP_INSTALL)
 	@test -f $@ || { echo "$< exists, but $@ does not."; echo "Suggest removing $<."; exit 1; }
 
 $(libffi_HEADERS): $(libffi_STAMP_INSTALL) | $$(dir $$@)/.
-	cp -f libffi/build/inst/lib/libffi-*/include/$(notdir $@) $@
+	cp -f libffi/build/inst/${ghclibdir}/libffi-*/include/$(notdir $@) $@
 
 $(eval $(call clean-target,libffi,, \
     libffi/build $(wildcard libffi/stamp.ffi.*) libffi/dist-install))
