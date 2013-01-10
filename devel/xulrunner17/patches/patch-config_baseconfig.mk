$NetBSD: patch-config_baseconfig.mk,v 1.1 2013/01/10 16:17:10 ryoon Exp $

--- config/baseconfig.mk.orig	2012-10-02 14:37:17.000000000 +0000
+++ config/baseconfig.mk
@@ -1,9 +1,9 @@
 INCLUDED_AUTOCONF_MK = 1
 
-includedir := $(includedir)/$(MOZ_APP_NAME)-$(MOZ_APP_VERSION)
-idldir = $(datadir)/idl/$(MOZ_APP_NAME)-$(MOZ_APP_VERSION)
-installdir = $(libdir)/$(MOZ_APP_NAME)-$(MOZ_APP_VERSION)
-sdkdir = $(libdir)/$(MOZ_APP_NAME)-devel-$(MOZ_APP_VERSION)
+includedir := $(includedir)/${MOZILLA_PKG_NAME}
+idldir = $(datadir)/idl/${MOZILLA_PKG_NAME}
+installdir = $(libdir)/${MOZILLA_PKG_NAME}
+sdkdir = $(libdir)/${MOZILLA_PKG_NAME}
 DIST = $(DEPTH)/dist
 
 # We do magic with OBJ_SUFFIX in config.mk, the following ensures we don't
