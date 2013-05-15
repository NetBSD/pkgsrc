$NetBSD: patch-.._config_NetBSD.mk,v 1.1 2013/05/15 06:58:50 jnemeth Exp $

--- ../config/NetBSD.mk.orig	2011-03-25 11:42:47.000000000 +0100
+++ ../config/NetBSD.mk	2011-04-15 11:36:19.000000000 +0200
@@ -7,12 +7,13 @@
 LIBEXEC = $(PREFIX)/libexec
 PRIVATE_BINDIR = $(BINDIR)
 
+MANDIR = $(PREFIX)/man
+MAN1DIR = $(MANDIR)/man1
+MAN8DIR = $(MANDIR)/man8
+
 DLOPEN_LIBS =
 
-ifeq ($(PREFIX),/usr)
-XEN_LOCK_DIR = /var/lib
-else
-XEN_LOCK_DIR = $(PREFIX)/var/lib
-endif
+XEN_LOCK_DIR = $(VARBASE)/run
+XEN_EXAMPLES_DIR=$(PREFIX)/share/examples/xen
 
 WGET = ftp
