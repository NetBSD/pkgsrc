$NetBSD: patch-src_kbibtex__part.h,v 1.1 2013/03/28 21:43:10 joerg Exp $

--- src/kbibtex_part.h.orig	2013-03-27 10:48:10.000000000 +0000
+++ src/kbibtex_part.h
@@ -43,7 +43,6 @@ class KAction;
 class KActionMenu;
 class KToggleAction;
 class KMainWindow;
-class KBibTeX::WebQuery;
 
 class KBibTeXPart : public KParts::ReadWritePart
 {
