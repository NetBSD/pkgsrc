$NetBSD: patch-ghc.mk,v 1.1 2021/05/01 01:24:50 pho Exp $

Use the wrapper scripts for ghc as we can't use the ones from the DESTDIR
as the libraries are not in the right place yet.

--- ghc.mk.orig	2017-01-03 15:59:18.000000000 +0000
+++ ghc.mk
@@ -960,6 +960,12 @@ endif
 
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
@@ -969,6 +975,7 @@ else
 INSTALLED_GHC_REAL=$(DESTDIR)$(bindir)/ghc.exe
 INSTALLED_GHC_PKG_REAL=$(DESTDIR)$(bindir)/ghc-pkg.exe
 endif
+endif
 
 # Set the INSTALL_DISTDIR_p for each package; compiler is special
 $(foreach p,$(filter-out compiler,$(INSTALL_PACKAGES)),\
