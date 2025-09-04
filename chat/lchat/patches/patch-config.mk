$NetBSD: patch-config.mk,v 1.1 2025/09/04 17:23:50 vins Exp $

* pkgsrc PREFIX support.
* Do not override CFLAGS and LIBS.

--- config.mk.orig	2025-09-04 16:02:51.758000596 +0000
+++ config.mk
@@ -1,12 +1,12 @@
 VERSION = 1.0
 
 # paths
-PREFIX	= /usr/local
+PREFIX	= @PREFIX@
 BINDIR	= $(PREFIX)/bin
-MANDIR	= $(PREFIX)/man
+MANDIR	= $(PREFIX)/@PKGMANDIR@
 MAN1DIR	= $(MANDIR)/man1
 
-CFLAGS = -std=c99 -pedantic -Wall -Wextra -I/usr/local/include
+CFLAGS	+= -std=c99 -pedantic -Wall -Wextra
 
 # grapheme.h
-LIBS = -L/usr/local/lib -lgrapheme
+LIBS	+= $(LDFLAGS) -lgrapheme
