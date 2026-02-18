$NetBSD: patch-libs.mk,v 1.7.28.1 2026/02/18 15:57:51 maya Exp $

Do not install debug library.

--- libs.mk.orig	2026-01-08 16:01:40.000000000 +0000
+++ libs.mk
@@ -190,9 +190,6 @@ INSTALL-LIBS-$(CONFIG_SHARED) += $(forea
 endif
 else
 INSTALL-LIBS-$(CONFIG_STATIC) += $(LIBSUBDIR)/libvpx.a
-ifeq ($(CONFIG_STATIC),yes)
-INSTALL-LIBS-$(CONFIG_DEBUG_LIBS) += $(LIBSUBDIR)/libvpx_g.a
-endif
 endif
 
 CODEC_SRCS=$(call enabled,CODEC_SRCS)
@@ -297,8 +294,8 @@ endif # ifeq ($(CONFIG_MSVS),yes)
 else # ifeq ($(CONFIG_EXTERNAL_BUILD),yes)
 LIBVPX_OBJS=$(call objs, $(filter-out $(ASM_INCLUDES), $(CODEC_SRCS)))
 OBJS-yes += $(LIBVPX_OBJS)
-LIBS-$(if yes,$(CONFIG_STATIC)) += $(BUILD_PFX)libvpx.a $(BUILD_PFX)libvpx_g.a
-$(BUILD_PFX)libvpx_g.a: $(LIBVPX_OBJS)
+LIBS-$(if yes,$(CONFIG_STATIC)) += $(BUILD_PFX)libvpx.a
+$(BUILD_PFX)libvpx.a: $(LIBVPX_OBJS)
 
 # Updating version info.
 # https://www.gnu.org/software/libtool/manual/libtool.html#Updating-version-info
@@ -414,8 +411,8 @@ CLEAN-OBJS += vpx.pc
 ifeq ($(CONFIG_ENCODERS),yes)
   RC_RTC_OBJS=$(call objs,$(RC_RTC_SRCS))
   OBJS-yes += $(RC_RTC_OBJS)
-  LIBS-yes += $(BUILD_PFX)libvpxrc.a $(BUILD_PFX)libvpxrc_g.a
-  $(BUILD_PFX)libvpxrc_g.a: $(RC_RTC_OBJS)
+  LIBS-yes += $(BUILD_PFX)libvpxrc.a
+  $(BUILD_PFX)libvpxrc.a: $(RC_RTC_OBJS)
 endif
 
 endif # ifeq ($(CONFIG_EXTERNAL_BUILD),yes)
@@ -634,8 +631,8 @@ GTEST_INCLUDES := -I$(SRC_PATH_BARE)/thi
 GTEST_INCLUDES += -I$(SRC_PATH_BARE)/third_party/googletest/src/include
 $(GTEST_OBJS) $(GTEST_OBJS:.o=.d): CXXFLAGS += $(GTEST_INCLUDES)
 OBJS-yes += $(GTEST_OBJS)
-LIBS-yes += $(BUILD_PFX)libgtest.a $(BUILD_PFX)libgtest_g.a
-$(BUILD_PFX)libgtest_g.a: $(GTEST_OBJS)
+LIBS-yes += $(BUILD_PFX)libgtest.a
+$(BUILD_PFX)libgtest.a: $(GTEST_OBJS)
 
 LIBVPX_TEST_OBJS=$(sort $(call objs,$(LIBVPX_TEST_SRCS)))
 $(LIBVPX_TEST_OBJS) $(LIBVPX_TEST_OBJS:.o=.d): CXXFLAGS += $(GTEST_INCLUDES)
