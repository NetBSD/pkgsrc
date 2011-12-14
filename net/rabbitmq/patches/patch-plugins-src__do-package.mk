$NetBSD: patch-plugins-src__do-package.mk,v 1.1 2011/12/14 11:55:20 fhajny Exp $

Drop dependency on gsed, gcp.
--- plugins-src/do-package.mk.orig	2011-11-08 16:55:55.000000000 +0000
+++ plugins-src/do-package.mk
@@ -286,7 +286,7 @@ $(eval $(foreach D,$(TEST_SOURCE_DIRS),$
 define run_broker
 	rm -rf $(TEST_TMPDIR)
 	mkdir -p $(foreach D,log plugins $(NODENAME),$(TEST_TMPDIR)/$(D))
-	cp -a $(PACKAGE_DIR)/dist/*.ez $(TEST_TMPDIR)/plugins
+	cp -pR $(PACKAGE_DIR)/dist/*.ez $(TEST_TMPDIR)/plugins
 	$(call copy,$(3),$(TEST_TMPDIR)/plugins)
 	rm -f $(TEST_TMPDIR)/plugins/rabbit_common*.ez
 	for plugin in \
@@ -375,7 +375,7 @@ $(APP_DONE): $(EBIN_BEAMS) $(INCLUDE_HRL
 	mkdir -p $(APP_DIR)/ebin $(APP_DIR)/include
 	@echo [elided] copy beams to ebin
 	@$(call copy,$(EBIN_BEAMS),$(APP_DIR)/ebin)
-	cp -a $(APP_FILE) $(APP_DIR)/ebin/$(APP_NAME).app
+	cp -pR $(APP_FILE) $(APP_DIR)/ebin/$(APP_NAME).app
 	$(call copy,$(INCLUDE_HRLS),$(APP_DIR)/include)
 	$(construct_app_commands)
 	touch $$@
@@ -414,8 +414,8 @@ $(DEPS_FILE): $(SOURCE_ERLS) $(INCLUDE_H
 	@echo [elided] generate deps
 	@$$(if $$^,echo $$(subst : ,:,$$(foreach F,$$^,$$(abspath $$(F)):)) | escript $(abspath $(UMBRELLA_BASE_DIR)/generate_deps) $$@ '$$$$(EBIN_DIR)',echo >$$@)
 	@echo [elided] fix test deps
-	@$$(foreach F,$(TEST_EBIN_BEAMS),sed -i -e 's|^$$$$(EBIN_DIR)/$$(notdir $$(F)):|$$$$(TEST_EBIN_DIR)/$$(notdir $$(F)):|' $$@ && ) :
-	sed -i -e 's|$$@|$$$$(DEPS_FILE)|' $$@
+	@$$(foreach F,$(TEST_EBIN_BEAMS),sed -e 's|^$$$$(EBIN_DIR)/$$(notdir $$(F)):|$$$$(TEST_EBIN_DIR)/$$(notdir $$(F)):|' $$@  > $$@.tmp && mv $$@.tmp $$@ && ) :
+	sed -e 's|$$@|$$$$(DEPS_FILE)|' $$@ > $$@.tmp && mv $$@.tmp $$@
 
 $(eval $(call safe_include,$(DEPS_FILE)))
 
