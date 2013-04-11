$NetBSD: patch-Config.mk,v 1.1 2013/04/11 19:57:51 joerg Exp $

--- Config.mk.orig	2012-12-18 12:54:16.000000000 +0000
+++ Config.mk
@@ -16,6 +16,8 @@ SHELL     ?= /bin/sh
 HOSTCC      = gcc
 HOSTCFLAGS  = -Wall -Werror -Wstrict-prototypes -O2 -fomit-frame-pointer
 HOSTCFLAGS += -fno-strict-aliasing
+HOSTCFLAGS += ${EXTRA_CFLAGS}
+CFLAGS     += ${EXTRA_CFLAGS}
 
 DISTDIR     ?= $(XEN_ROOT)/dist
 DESTDIR     ?= /
