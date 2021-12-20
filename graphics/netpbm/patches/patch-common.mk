$NetBSD: patch-common.mk,v 1.4 2021/12/20 20:41:38 nia Exp $

Simplify install target.

--- common.mk.orig	2021-11-16 12:20:01.000000000 +0000
+++ common.mk
@@ -482,7 +482,7 @@ endif
 
 PKGMANSUBDIRS = man1 man3 man5 web
 
-PKGSUBDIRS = bin include include/netpbm lib sharedlink staticlink misc \
+PKGSUBDIRS = bin include include/netpbm lib misc \
   $(PKGMANSUBDIRS:%=$(PKGMANDIR)/%)
 
 $(PKGSUBDIRS:%=$(PKGDIR)/%):
