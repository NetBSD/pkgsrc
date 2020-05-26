$NetBSD: patch-Config.mk,v 1.1 2020/05/26 11:12:11 bouyer Exp $

--- Config.mk.orig	2018-04-17 19:21:31.000000000 +0200
+++ Config.mk	2018-04-23 16:15:57.000000000 +0200
@@ -31,7 +31,7 @@
 
 # Tools to run on system hosting the build
 HOSTCFLAGS  = -Wall -Werror -Wstrict-prototypes -O2 -fomit-frame-pointer
-HOSTCFLAGS += -fno-strict-aliasing
+HOSTCFLAGS += -fno-strict-aliasing ${EXTRA_HOSTCFLAGS}
 
 DISTDIR     ?= $(XEN_ROOT)/dist
 DESTDIR     ?= /
@@ -219,6 +219,8 @@
 
 CFLAGS += -Wall -Wstrict-prototypes
 
+CFLAGS += ${EXTRA_CFLAGS}
+
 $(call cc-option-add,HOSTCFLAGS,HOSTCC,-Wdeclaration-after-statement)
 $(call cc-option-add,CFLAGS,CC,-Wdeclaration-after-statement)
 $(call cc-option-add,CFLAGS,CC,-Wno-unused-but-set-variable)
