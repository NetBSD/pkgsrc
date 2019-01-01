$NetBSD: patch-config.mak,v 1.1 2019/01/01 16:30:29 wiz Exp $

Allow overriding man page installation directory.

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
