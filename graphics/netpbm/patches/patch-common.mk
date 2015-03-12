$NetBSD: patch-common.mk,v 1.3 2015/03/12 12:35:42 tnn Exp $

Simplify install target.
--- common.mk.orig	2014-09-08 21:26:50.000000000 +0000
+++ common.mk
@@ -465,7 +465,7 @@ endif
 
 PKGMANSUBDIRS = man1 man3 man5 web
 
-PKGSUBDIRS = bin include include/netpbm lib link misc \
+PKGSUBDIRS = bin include include/netpbm lib misc \
   $(PKGMANSUBDIRS:%=$(PKGMANDIR)/%)
 
 $(PKGSUBDIRS:%=$(PKGDIR)/%):
