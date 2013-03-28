$NetBSD: patch-src_documentlistview.h,v 1.1 2013/03/28 21:43:10 joerg Exp $

--- src/documentlistview.h.orig	2013-03-27 10:46:40.000000000 +0000
+++ src/documentlistview.h
@@ -32,8 +32,6 @@ class KURL;
 class KActionMenu;
 class KPopupMenu;
 
-enum BibTeX::Element::FilterType;
-
 namespace KBibTeX
 {
     class DocumentWidget;
