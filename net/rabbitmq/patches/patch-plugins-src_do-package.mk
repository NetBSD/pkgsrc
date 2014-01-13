$NetBSD: patch-plugins-src_do-package.mk,v 1.1 2014/01/13 12:10:23 fhajny Exp $

Fix module versioning with gmake<4.
--- plugins-src/do-package.mk.orig	2013-12-10 16:18:44.000000000 +0000
+++ plugins-src/do-package.mk
@@ -545,7 +545,7 @@ $(PACKAGE_DIR)/dist/.done: $(PACKAGE_DIR
 # makefile.
 $(PACKAGE_DIR)/dist/.done.$(VERSION): $(PACKAGE_DIR)/Makefile $(wildcard $(PACKAGE_DIR)/*.mk) $(wildcard $(PACKAGE_DIR)/src/*.erl) $(wildcard $(PACKAGE_DIR)/include/*.hrl) $(wildcard $(PACKAGE_DIR)/*.py) $(foreach DEP,$(NON_INTEGRATED_DEPS_$(PACKAGE_DIR)),$(call package_to_path,$(DEP))/dist/.done)
 	rm -rf $$(@D)
-	$$(MAKE) -C $(PACKAGE_DIR)
+	$$(MAKE) -C $(PACKAGE_DIR) VERSION=$(VERSION)
 	mkdir -p $$(@D)
 	touch $$@
 
