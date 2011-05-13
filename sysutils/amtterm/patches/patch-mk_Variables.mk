$NetBSD: patch-mk_Variables.mk,v 1.1.1.1 2011/05/13 13:24:01 obache Exp $

* honor PKGMANDIR

--- mk/Variables.mk.orig	2008-10-30 09:29:19.000000000 +0000
+++ mk/Variables.mk
@@ -9,7 +9,7 @@ bindir	=  $(DESTDIR)$(prefix)/bin
 sbindir	=  $(DESTDIR)$(prefix)/sbin
 libdir  =  $(DESTDIR)$(prefix)/$(LIB)
 shrdir  =  $(DESTDIR)$(prefix)/share
-mandir	=  $(shrdir)/man
+mandir	=  $(DESTDIR)$(prefix)/${PKGMANDIR}
 locdir  =  $(shrdir)/locale
 appdir  =  $(shrdir)/applications
 
