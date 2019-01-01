$NetBSD: patch-config.mak,v 1.2 2019/01/01 16:34:09 wiz Exp $

Allow overriding man page installation directory.
https://github.com/otfried/ipe-issues/issues/200

--- config.mak.orig	2016-12-09 14:09:08.000000000 +0000
+++ config.mak
@@ -112,6 +112,6 @@ IPEDOCDIR = $(IPEPREFIX)/share/ipe/$(IPE
 #
 # The Ipe manual pages are installed into IPEMANDIR
 #
-IPEMANDIR = $(IPEPREFIX)/share/man/man1
+IPEMANDIR ?= $(IPEPREFIX)/share/man/man1
 #
 # --------------------------------------------------------------------
