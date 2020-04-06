$NetBSD: patch-.._.._config_rules.mk,v 1.1 2020/04/06 04:58:42 wiz Exp $

Add soname switch to linker, regardless of Operating System

Bug-Debian: http://bugs.debian.org/746705

--- ../../config/rules.mk.orig	2019-07-01 09:07:38.000000000 +0000
+++ ../../config/rules.mk
@@ -367,6 +367,9 @@ endif
 endif
 EXTRA_DEPS += $(SYMBOLS_FILE)
 endif
+
+EXTRA_DSO_LDOPTS += -Wl,-soname,lib$(JS_LIBRARY_NAME).so.0
+
 #
 # GNU doesn't have path length limitation
 #
