$NetBSD: patch-ghc.mk,v 1.2 2019/12/29 16:59:09 pho Exp $

Fix building bootkits: we don't generate documentation for them.

--- ghc.mk.orig	2019-12-27 02:36:02.858039422 +0000
+++ ghc.mk
@@ -989,7 +989,6 @@ $(eval $(call bindist,.,\
     $(INSTALL_LIBRARY_DOCS) \
     $(addsuffix /*,$(INSTALL_HTML_DOC_DIRS)) \
     docs/index.html \
-    compiler/stage2/doc \
     $(wildcard libraries/*/dist-install/doc/) \
     $(wildcard libraries/*/*/dist-install/doc/) \
     $(filter-out settings,$(INSTALL_LIBS)) \
