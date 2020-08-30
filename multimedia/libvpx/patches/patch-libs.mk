$NetBSD: patch-libs.mk,v 1.5 2020/08/30 12:33:29 js Exp $

Do not install debug library.

--- libs.mk.orig	2020-07-30 19:59:15.000000000 +0000
+++ libs.mk
@@ -170,7 +170,6 @@ INSTALL-LIBS-$(CONFIG_SHARED) += $(forea
 endif
 else
 INSTALL-LIBS-$(CONFIG_STATIC) += $(LIBSUBDIR)/libvpx.a
-INSTALL-LIBS-$(CONFIG_DEBUG_LIBS) += $(LIBSUBDIR)/libvpx_g.a
 endif
 
 ifeq ($(CONFIG_VP9_ENCODER)$(CONFIG_RATE_CTRL),yesyes)
@@ -278,8 +277,8 @@ endif # ifeq ($(CONFIG_MSVS),yes)
 else # ifeq ($(CONFIG_EXTERNAL_BUILD),yes)
 LIBVPX_OBJS=$(call objs, $(filter-out $(ASM_INCLUDES), $(CODEC_SRCS)))
 OBJS-yes += $(LIBVPX_OBJS)
-LIBS-$(if yes,$(CONFIG_STATIC)) += $(BUILD_PFX)libvpx.a $(BUILD_PFX)libvpx_g.a
-$(BUILD_PFX)libvpx_g.a: $(LIBVPX_OBJS)
+LIBS-$(if yes,$(CONFIG_STATIC)) += $(BUILD_PFX)libvpx.a
+$(BUILD_PFX)libvpx.a: $(LIBVPX_OBJS)
 
 SO_VERSION_MAJOR := 6
 SO_VERSION_MINOR := 3
@@ -384,15 +383,15 @@ ifeq ($(CONFIG_VP9_ENCODER),yes)
   RC_RTC_OBJS=$(call objs,$(RC_RTC_SRCS))
   RC_RTC_OBJS=$(call objs,$(RC_RTC_SRCS))
   OBJS-yes += $(RC_RTC_OBJS)
-  LIBS-yes += $(BUILD_PFX)libvp9rc.a $(BUILD_PFX)libvp9rc_g.a
-  $(BUILD_PFX)libvp9rc_g.a: $(RC_RTC_OBJS)
+  LIBS-yes += $(BUILD_PFX)libvp9rc.a
+  $(BUILD_PFX)libvp9rc.a: $(RC_RTC_OBJS)
 endif
 
 ifeq ($(CONFIG_VP9_ENCODER)$(CONFIG_RATE_CTRL),yesyes)
   SIMPLE_ENCODE_OBJS=$(call objs,$(SIMPLE_ENCODE_SRCS))
   OBJS-yes += $(SIMPLE_ENCODE_OBJS)
-  LIBS-yes += $(BUILD_PFX)libsimple_encode.a $(BUILD_PFX)libsimple_encode_g.a
-  $(BUILD_PFX)libsimple_encode_g.a: $(SIMPLE_ENCODE_OBJS)
+  LIBS-yes += $(BUILD_PFX)libsimple_encode.a
+  $(BUILD_PFX)libsimple_encode.a: $(SIMPLE_ENCODE_OBJS)
 endif
 
 endif # ifeq ($(CONFIG_EXTERNAL_BUILD),yes)
