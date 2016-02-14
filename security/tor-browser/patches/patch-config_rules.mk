$NetBSD: patch-config_rules.mk,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- config/rules.mk.orig	2015-02-17 21:40:40.000000000 +0000
+++ config/rules.mk
@@ -765,6 +765,7 @@ endif
 ifdef DTRACE_PROBE_OBJ
 EXTRA_DEPS += $(DTRACE_PROBE_OBJ)
 OBJS += $(DTRACE_PROBE_OBJ)
+EXCLUDED_OBJS += $(DTRACE_PROBE_OBJ)
 endif
 
 $(filter %.$(LIB_SUFFIX),$(LIBRARY)): $(OBJS) $(STATIC_LIBS_DEPS) $(filter %.$(LIB_SUFFIX),$(EXTRA_LIBS)) $(EXTRA_DEPS) $(GLOBAL_DEPS)
