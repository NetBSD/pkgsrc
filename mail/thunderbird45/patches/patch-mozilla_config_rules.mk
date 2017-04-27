$NetBSD: patch-mozilla_config_rules.mk,v 1.1 2017/04/27 13:38:18 ryoon Exp $

--- mozilla/config/rules.mk.orig	2016-04-07 21:33:18.000000000 +0000
+++ mozilla/config/rules.mk
@@ -773,6 +773,7 @@ endif
 ifdef DTRACE_PROBE_OBJ
 EXTRA_DEPS += $(DTRACE_PROBE_OBJ)
 OBJS += $(DTRACE_PROBE_OBJ)
+EXCLUDED_OBJS += $(DTRACE_PROBE_OBJ)
 endif
 
 $(filter %.$(LIB_SUFFIX),$(LIBRARY)): $(OBJS) $(STATIC_LIBS_DEPS) $(filter %.$(LIB_SUFFIX),$(EXTRA_LIBS)) $(EXTRA_DEPS) $(GLOBAL_DEPS)
