$NetBSD: patch-Instance_framework.make,v 1.2 2015/04/19 04:13:26 manu Exp $

Hunk #1: Don't create interfaces don't derive from NSObject

Hunk #2 and #3: Apply fix from upstream, required to build SOGo
http://svn.gna.org/viewcvs/gnustep?view=revision&revision=36185

--- Instance/framework.make.orig	2013-03-23 21:46:20.000000000 +0000
+++ Instance/framework.make
@@ -484,7 +484,7 @@ $(DUMMY_FRAMEWORK_FILE): $(DERIVED_SOURC
 	fi; \
 	echo "$$classarray" > $(DUMMY_FRAMEWORK_CLASS_LIST); \
 	echo "#include <Foundation/NSString.h>" > $@; \
-	echo "@interface $(DUMMY_FRAMEWORK)" >> $@; \
+	echo "@interface $(DUMMY_FRAMEWORK) : NSObject" >> $@; \
 	echo "+ (NSString *)frameworkEnv;" >> $@; \
 	echo "+ (NSString *)frameworkPath;" >> $@; \
 	echo "+ (NSString *)frameworkVersion;" >> $@; \
@@ -536,7 +536,7 @@
 $(GNUSTEP_BUILD_DIR)/$(GNUSTEP_INSTANCE).framework/$(GNUSTEP_TARGET_LDIR):
 	$(ECHO_CREATING)$(MKDIRS) $@$(END_ECHO)
 
-$(GNUSTEP_BUILD_DIR)/$(GNUSTEP_INSTANCE).framework/$(GNUSTEP_TARGET_LDIR)/$(GNUSTEP_INSTANCE): $(GNUSTEP_BUILD_DIR)/$(GNUSTEP_INSTANCE).framework/$(GNUSTEP_TARGET_LDIR)/
+$(GNUSTEP_BUILD_DIR)/$(GNUSTEP_INSTANCE).framework/$(GNUSTEP_TARGET_LDIR)/$(GNUSTEP_INSTANCE): $(GNUSTEP_BUILD_DIR)/$(GNUSTEP_INSTANCE).framework/$(GNUSTEP_TARGET_LDIR)
 ifeq ($(MAKE_CURRENT_VERSION),yes)
 	$(ECHO_NOTHING)cd $(GNUSTEP_BUILD_DIR)/$(GNUSTEP_INSTANCE).framework; \
 	$(RM_LN_S) $(GNUSTEP_INSTANCE); \
@@ -562,7 +562,7 @@
 $(GNUSTEP_BUILD_DIR)/$(GNUSTEP_INSTANCE).framework/$(GNUSTEP_TARGET_LDIR):
 	$(ECHO_CREATING)$(MKDIRS) $@$(END_ECHO)
 
-$(GNUSTEP_BUILD_DIR)/$(GNUSTEP_INSTANCE).framework/$(GNUSTEP_TARGET_LDIR)/$(GNUSTEP_INSTANCE): $(GNUSTEP_BUILD_DIR)/$(GNUSTEP_INSTANCE).framework/$(GNUSTEP_TARGET_LDIR)/
+$(GNUSTEP_BUILD_DIR)/$(GNUSTEP_INSTANCE).framework/$(GNUSTEP_TARGET_LDIR)/$(GNUSTEP_INSTANCE): $(GNUSTEP_BUILD_DIR)/$(GNUSTEP_INSTANCE).framework/$(GNUSTEP_TARGET_LDIR)
 ifeq ($(MAKE_CURRENT_VERSION),yes)
 	$(ECHO_NOTHING)cd $(GNUSTEP_BUILD_DIR)/$(GNUSTEP_INSTANCE).framework/$(GNUSTEP_TARGET_LDIR); \
 	$(RM_LN_S) $(GNUSTEP_INSTANCE) $(FRAMEWORK_LIBRARY_FILE); \
