$NetBSD: patch-krusader_Panel_krview.h,v 1.1 2012/12/22 02:31:33 joerg Exp $

--- krusader/Panel/krview.h.orig	2012-12-22 01:12:56.000000000 +0000
+++ krusader/Panel/krview.h
@@ -133,6 +133,8 @@ protected:
  */ 
 class KrView {
 friend class KrViewItem;
+friend class KrDetailedViewItem;
+friend class KrBriefViewItem;
 public:
   // instantiating a new view
   // 1. new KrView
