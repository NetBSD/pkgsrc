$NetBSD: patch-sc_source_filter_inc_xiroot.hxx,v 1.1 2013/04/01 12:19:14 joerg Exp $

--- sc/source/filter/inc/xiroot.hxx.orig	2013-03-30 20:09:09.000000000 +0000
+++ sc/source/filter/inc/xiroot.hxx
@@ -193,7 +193,7 @@ public:
     String              GetScAddInName( const String& rXclName ) const;
 
 private:
-    mutable XclImpRootData& mrImpData;      /// Reference to the global import data struct.
+    XclImpRootData& mrImpData;      /// Reference to the global import data struct.
 };
 
 // ============================================================================
