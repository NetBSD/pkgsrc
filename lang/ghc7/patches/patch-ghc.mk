$NetBSD: patch-ghc.mk,v 1.3 2021/04/30 18:52:05 pho Exp $

* Use the wrapper scripts for ghc as we can't use the ones from the DESTDIR
  as the libraries are not in the right place yet.

* Fix building bootkits: we don't generate documentation for them.

--- ghc.mk.orig	2015-10-19 15:59:58.000000000 +0000
+++ ghc.mk
@@ -897,6 +897,12 @@ endif
 
 INSTALLED_PACKAGE_CONF=$(DESTDIR)$(topdir)/package.conf.d
 
+ifneq "$(BINDIST)" "YES"
+# when installing ghc-stage2 we can't run target's
+# 'ghc-pkg' and 'ghc-stage2' but those are needed for registration.
+INSTALLED_GHC_REAL=$(TOP)/inplace/bin/ghc-stage1
+INSTALLED_GHC_PKG_REAL=$(TOP)/utils/ghc-pkg/dist/build/tmp/ghc-pkg
+else
 # Install packages in the right order, so that ghc-pkg doesn't complain.
 # Also, install ghc-pkg first.
 ifeq "$(Windows_Host)" "NO"
@@ -906,6 +912,7 @@ else
 INSTALLED_GHC_REAL=$(DESTDIR)$(bindir)/ghc.exe
 INSTALLED_GHC_PKG_REAL=$(DESTDIR)$(bindir)/ghc-pkg.exe
 endif
+endif
 
 # Set the INSTALL_DISTDIR_p for each package; compiler is special
 $(foreach p,$(filter-out compiler,$(INSTALL_PACKAGES)),\
@@ -989,7 +996,6 @@ $(eval $(call bindist,.,\
     $(INSTALL_LIBRARY_DOCS) \
     $(addsuffix /*,$(INSTALL_HTML_DOC_DIRS)) \
     docs/index.html \
-    compiler/stage2/doc \
     $(wildcard libraries/*/dist-install/doc/) \
     $(wildcard libraries/*/*/dist-install/doc/) \
     $(filter-out settings,$(INSTALL_LIBS)) \
