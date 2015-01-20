$NetBSD: patch-.._Config.mk,v 1.1 2015/01/20 16:42:13 bouyer Exp $

--- ../Config.mk.orig	2015-01-12 17:53:24.000000000 +0100
+++ ../Config.mk	2015-01-19 13:16:16.000000000 +0100
@@ -38,7 +38,7 @@
 # Tools to run on system hosting the build
 HOSTCC      = gcc
 HOSTCFLAGS  = -Wall -Werror -Wstrict-prototypes -O2 -fomit-frame-pointer
-HOSTCFLAGS += -fno-strict-aliasing
+HOSTCFLAGS += -fno-strict-aliasing ${EXTRA_HOSTCFLAGS}
 
 DISTDIR     ?= $(XEN_ROOT)/dist
 DESTDIR     ?= /
@@ -194,6 +194,8 @@
 # and is a bit too fierce about unused return values
 CFLAGS-$(clang) += -Wno-parentheses -Wno-format -Wno-unused-value
 
+CFLAGS += ${EXTRA_CFLAGS}
+
 $(call cc-option-add,HOSTCFLAGS,HOSTCC,-Wdeclaration-after-statement)
 $(call cc-option-add,CFLAGS,CC,-Wdeclaration-after-statement)
 $(call cc-option-add,CFLAGS,CC,-Wno-unused-but-set-variable)
