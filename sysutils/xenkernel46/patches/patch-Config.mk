$NetBSD: patch-Config.mk,v 1.1.1.1 2016/07/04 07:25:13 jnemeth Exp $

--- Config.mk.orig	2015-01-12 17:53:24.000000000 +0100
+++ Config.mk	2015-01-19 12:29:14.000000000 +0100
@@ -39,6 +39,8 @@
 HOSTCC      = gcc
 HOSTCFLAGS  = -Wall -Werror -Wstrict-prototypes -O2 -fomit-frame-pointer
 HOSTCFLAGS += -fno-strict-aliasing
+HOSTCFLAGS += ${EXTRA_CFLAGS}
+CFLAGS     += ${EXTRA_CFLAGS}
 
 DISTDIR     ?= $(XEN_ROOT)/dist
 DESTDIR     ?= /
