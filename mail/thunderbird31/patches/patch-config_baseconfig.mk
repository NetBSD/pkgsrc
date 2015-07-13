$NetBSD: patch-config_baseconfig.mk,v 1.1 2015/07/13 17:49:26 ryoon Exp $

--- config/baseconfig.mk.orig	2014-07-18 00:04:05.000000000 +0000
+++ config/baseconfig.mk
@@ -1,7 +1,7 @@
-includedir := $(includedir)/$(MOZ_APP_NAME)-$(MOZ_APP_VERSION)
-idldir = $(datadir)/idl/$(MOZ_APP_NAME)-$(MOZ_APP_VERSION)
-installdir = $(libdir)/$(MOZ_APP_NAME)-$(MOZ_APP_VERSION)
-sdkdir = $(libdir)/$(MOZ_APP_NAME)-devel-$(MOZ_APP_VERSION)
+includedir := $(includedir)/$(MOZILLA_PKG_NAME)
+idldir = $(datadir)/idl/$(MOZILLA_PKG_NAME)
+installdir = $(libdir)/$(MOZILLA_PKG_NAME)
+sdkdir = $(libdir)/$(MOZILLA_PKG_NAME)-sdk
 MOZILLA_SRCDIR = $(topsrcdir)/mozilla
 MOZDEPTH = $(DEPTH)/mozilla
 DIST = $(MOZDEPTH)/dist
