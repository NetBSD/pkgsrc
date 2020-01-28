$NetBSD: patch-libs.mk,v 1.3 2020/01/28 19:20:09 adam Exp $

Do not install debug library.

--- libs.mk.orig	2019-12-09 23:09:20.000000000 +0000
+++ libs.mk
@@ -162,7 +162,6 @@ INSTALL-LIBS-$(CONFIG_SHARED) += $(forea
 endif
 else
 INSTALL-LIBS-$(CONFIG_STATIC) += $(LIBSUBDIR)/libvpx.a
-INSTALL-LIBS-$(CONFIG_DEBUG_LIBS) += $(LIBSUBDIR)/libvpx_g.a
 endif
 
 CODEC_SRCS=$(call enabled,CODEC_SRCS)
@@ -229,8 +228,8 @@ endif
 else
 LIBVPX_OBJS=$(call objs, $(filter-out $(ASM_INCLUDES), $(CODEC_SRCS)))
 OBJS-yes += $(LIBVPX_OBJS)
-LIBS-$(if yes,$(CONFIG_STATIC)) += $(BUILD_PFX)libvpx.a $(BUILD_PFX)libvpx_g.a
-$(BUILD_PFX)libvpx_g.a: $(LIBVPX_OBJS)
+LIBS-$(if yes,$(CONFIG_STATIC)) += $(BUILD_PFX)libvpx.a
+$(BUILD_PFX)libvpx.a: $(LIBVPX_OBJS)
 
 SO_VERSION_MAJOR := 6
 SO_VERSION_MINOR := 2
