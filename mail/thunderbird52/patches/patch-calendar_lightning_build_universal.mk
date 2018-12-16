$NetBSD: patch-calendar_lightning_build_universal.mk,v 1.1 2018/12/16 08:29:48 ryoon Exp $

--- calendar/lightning/build/universal.mk.orig	2016-04-07 21:14:23.000000000 +0000
+++ calendar/lightning/build/universal.mk
@@ -19,7 +19,7 @@ include $(topsrcdir)/mozilla/toolkit/moz
 
 THUNDERBIRD_VERSION := $(shell cat $(topsrcdir)/mail/config/version.txt)
 LIGHTNING_VERSION := $(shell $(PYTHON) $(topsrcdir)/calendar/lightning/build/makeversion.py $(word 1,$(MOZ_PKG_VERSION) $(THUNDERBIRD_VERSION)))
-XPI_PKGNAME = lightning-$(LIGHTNING_VERSION).$(AB_CD).$(MOZ_PKG_PLATFORM)
+XPI_PKGNAME = lightning
 
 STANDALONE_MAKEFILE := 1
 include $(TOPSRCDIR)/config/config.mk
