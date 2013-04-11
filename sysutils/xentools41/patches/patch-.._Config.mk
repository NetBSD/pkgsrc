$NetBSD: patch-.._Config.mk,v 1.1 2013/04/11 19:57:53 joerg Exp $

--- ../Config.mk.orig	2013-03-25 09:51:57.000000000 +0000
+++ ../Config.mk
@@ -15,7 +15,7 @@ SHELL     ?= /bin/sh
 # Tools to run on system hosting the build
 HOSTCC      = gcc
 HOSTCFLAGS  = -Wall -Werror -Wstrict-prototypes -O2 -fomit-frame-pointer
-HOSTCFLAGS += -fno-strict-aliasing
+HOSTCFLAGS += -fno-strict-aliasing ${EXTRA_HOSTCFLAGS}
 
 DISTDIR     ?= $(XEN_ROOT)/dist
 DESTDIR     ?= /
@@ -141,6 +141,8 @@ CFLAGS += -Wall -Wstrict-prototypes
 # result of any casted expression causes a warning.
 CFLAGS += -Wno-unused-value
 
+CFLAGS += ${EXTRA_CFLAGS}
+
 $(call cc-option-add,HOSTCFLAGS,HOSTCC,-Wdeclaration-after-statement)
 $(call cc-option-add,CFLAGS,CC,-Wdeclaration-after-statement)
 $(call cc-option-add,CFLAGS,CC,-Wno-unused-but-set-variable)
