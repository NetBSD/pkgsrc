$NetBSD: patch-speech__tools_config_rules_compile__options.mak,v 1.1 2011/12/17 10:14:40 sbd Exp $

--- speech_tools/config/rules/compile_options.mak.orig	2001-04-04 13:11:27.000000000 +0000
+++ speech_tools/config/rules/compile_options.mak
@@ -172,3 +172,6 @@ ifneq ($(STATIC),0)
     LINKFLAGS += $(STATIC_LINKFLAGS)
 endif
 
+CFLAGS		+= $(BUILDLINK_CPPFLAGS)
+CXXFLAGS	+= $(BUILDLINK_CPPFLAGS)
+LINKFLAGS	+= $(BUILDLINK_LDFLAGS)
