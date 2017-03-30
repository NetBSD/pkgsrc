$NetBSD: patch-Config.mk,v 1.1 2017/03/30 09:15:10 bouyer Exp $

--- Config.mk.orig	2016-12-05 13:03:27.000000000 +0100
+++ Config.mk	2017-03-24 17:33:17.000000000 +0100
@@ -35,7 +35,7 @@
 
 # Tools to run on system hosting the build
 HOSTCFLAGS  = -Wall -Werror -Wstrict-prototypes -O2 -fomit-frame-pointer
-HOSTCFLAGS += -fno-strict-aliasing
+HOSTCFLAGS += -fno-strict-aliasing ${EXTRA_HOSTCFLAGS}
 
 DISTDIR     ?= $(XEN_ROOT)/dist
 DESTDIR     ?= /
@@ -221,6 +221,8 @@
 # and is a bit too fierce about unused return values
 CFLAGS-$(clang) += -Wno-parentheses -Wno-format -Wno-unused-value
 
+CFLAGS += ${EXTRA_CFLAGS}
+
 $(call cc-option-add,HOSTCFLAGS,HOSTCC,-Wdeclaration-after-statement)
 $(call cc-option-add,CFLAGS,CC,-Wdeclaration-after-statement)
 $(call cc-option-add,CFLAGS,CC,-Wno-unused-but-set-variable)
