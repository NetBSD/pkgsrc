$NetBSD: patch-sc_source_filter_inc_xeroot.hxx,v 1.1 2013/04/01 12:19:14 joerg Exp $

--- sc/source/filter/inc/xeroot.hxx.orig	2013-03-30 20:15:20.000000000 +0000
+++ sc/source/filter/inc/xeroot.hxx
@@ -159,7 +159,7 @@ private:
     XclExpRootData::XclExpLinkMgrRef GetLocalLinkMgrRef() const;
 
 private:
-    mutable XclExpRootData& mrExpData;      /// Reference to the global export data struct.
+    XclExpRootData& mrExpData;      /// Reference to the global export data struct.
 };
 
 // ============================================================================
