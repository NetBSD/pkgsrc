$NetBSD: patch-Config.mk,v 1.1 2017/03/30 09:15:09 bouyer Exp $

--- Config.mk.orig	2016-12-05 13:03:27.000000000 +0100
+++ Config.mk	2017-03-21 17:03:57.000000000 +0100
@@ -36,6 +36,9 @@
 # Tools to run on system hosting the build
 HOSTCFLAGS  = -Wall -Werror -Wstrict-prototypes -O2 -fomit-frame-pointer
 HOSTCFLAGS += -fno-strict-aliasing
+HOSTCFLAGS += ${EXTRA_CFLAGS}
+CFLAGS     += ${EXTRA_CFLAGS}
+
 
 DISTDIR     ?= $(XEN_ROOT)/dist
 DESTDIR     ?= /
