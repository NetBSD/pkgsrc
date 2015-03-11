$NetBSD: patch-common.mk,v 1.2 2015/03/11 23:19:58 tnn Exp $

Simplify install target.
--- common.mk.orig	2014-09-08 21:26:50.000000000 +0000
+++ common.mk
@@ -465,7 +465,7 @@ endif
 
 PKGMANSUBDIRS = man1 man3 man5 web
 
-PKGSUBDIRS = bin include include/netpbm lib link misc \
+PKGSUBDIRS = bin include include/netpbm lib misc \
   $(PKGMANSUBDIRS:%=$(PKGMANDIR)/%)
 
 $(PKGSUBDIRS:%=$(PKGDIR)/%):
@@ -510,7 +510,7 @@ install.man: install.man1 install.man3 i
 
 MANUALS1 = $(BINARIES) $(SCRIPTS)
 
-PKGMANDIR = man
+PKGMANDIR? = man
 
 install.man1: $(MANUALS1:%=%_installman1)
 
