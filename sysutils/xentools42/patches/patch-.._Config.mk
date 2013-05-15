$NetBSD: patch-.._Config.mk,v 1.1 2013/05/15 06:58:50 jnemeth Exp $

--- ../Config.mk.orig	2012-12-17 15:04:11.000000000 +0000
+++ ../Config.mk
@@ -25,7 +25,7 @@ SHELL     ?= /bin/sh
 # Tools to run on system hosting the build
 HOSTCC      = gcc
 HOSTCFLAGS  = -Wall -Werror -Wstrict-prototypes -O2 -fomit-frame-pointer
-HOSTCFLAGS += -fno-strict-aliasing
+HOSTCFLAGS += -fno-strict-aliasing ${EXTRA_HOSTCFLAGS}
 
 DISTDIR     ?= $(XEN_ROOT)/dist
 DESTDIR     ?= /
@@ -163,6 +163,8 @@ CFLAGS += -Wall -Wstrict-prototypes
 # and is a bit too fierce about unused return values
 CFLAGS-$(clang) += -Wno-parentheses -Wno-format -Wno-unused-value
 
+CFLAGS += ${EXTRA_CFLAGS}
+
 $(call cc-option-add,HOSTCFLAGS,HOSTCC,-Wdeclaration-after-statement)
 $(call cc-option-add,CFLAGS,CC,-Wdeclaration-after-statement)
 $(call cc-option-add,CFLAGS,CC,-Wno-unused-but-set-variable)
