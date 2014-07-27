$NetBSD: patch-calendar_lightning_build_universal.mk,v 1.1 2014/07/27 05:36:07 ryoon Exp $

--- calendar/lightning/build/universal.mk.orig	2013-10-23 22:00:45.000000000 +0000
+++ calendar/lightning/build/universal.mk
@@ -18,7 +18,7 @@ include $(DEPTH)/config/autoconf.mk
 include $(topsrcdir)/mozilla/toolkit/mozapps/installer/package-name.mk
 
 LIGHTNING_VERSION := $(shell cat $(topsrcdir)/calendar/sunbird/config/version.txt)
-XPI_PKGNAME = lightning-$(LIGHTNING_VERSION).$(AB_CD).$(MOZ_PKG_PLATFORM)
+XPI_PKGNAME = lightning
 
 include $(TOPSRCDIR)/config/config.mk
 
