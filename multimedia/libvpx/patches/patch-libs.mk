$NetBSD: patch-libs.mk,v 1.7 2022/07/15 11:04:33 adam Exp $

Do not install debug library.

--- libs.mk.orig	2022-06-28 19:00:48.000000000 +0000
+++ libs.mk
@@ -187,7 +187,6 @@ INSTALL-LIBS-$(CONFIG_SHARED) += $(forea
 endif
 else
 INSTALL-LIBS-$(CONFIG_STATIC) += $(LIBSUBDIR)/libvpx.a
-INSTALL-LIBS-$(CONFIG_DEBUG_LIBS) += $(LIBSUBDIR)/libvpx_g.a
 endif
 
 ifeq ($(CONFIG_VP9_ENCODER)$(CONFIG_RATE_CTRL),yesyes)
@@ -297,8 +296,8 @@ endif # ifeq ($(CONFIG_MSVS),yes)
 else # ifeq ($(CONFIG_EXTERNAL_BUILD),yes)
 LIBVPX_OBJS=$(call objs, $(filter-out $(ASM_INCLUDES), $(CODEC_SRCS)))
 OBJS-yes += $(LIBVPX_OBJS)
-LIBS-$(if yes,$(CONFIG_STATIC)) += $(BUILD_PFX)libvpx.a $(BUILD_PFX)libvpx_g.a
-$(BUILD_PFX)libvpx_g.a: $(LIBVPX_OBJS)
+LIBS-$(if yes,$(CONFIG_STATIC)) += $(BUILD_PFX)libvpx.a
+$(BUILD_PFX)libvpx.a: $(LIBVPX_OBJS)
 
 # Updating version info.
 # https://www.gnu.org/software/libtool/manual/libtool.html#Updating-version-info
@@ -414,15 +413,15 @@ CLEAN-OBJS += vpx.pc
 ifeq ($(CONFIG_ENCODERS),yes)
   RC_RTC_OBJS=$(call objs,$(RC_RTC_SRCS))
   OBJS-yes += $(RC_RTC_OBJS)
-  LIBS-yes += $(BUILD_PFX)libvpxrc.a $(BUILD_PFX)libvpxrc_g.a
-  $(BUILD_PFX)libvpxrc_g.a: $(RC_RTC_OBJS)
+  LIBS-yes += $(BUILD_PFX)libvpxrc.a
+  $(BUILD_PFX)libvpxrc.a: $(RC_RTC_OBJS)
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
