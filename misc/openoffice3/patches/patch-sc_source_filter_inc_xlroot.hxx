$NetBSD: patch-sc_source_filter_inc_xlroot.hxx,v 1.1 2013/04/01 12:19:14 joerg Exp $

--- sc/source/filter/inc/xlroot.hxx.orig	2013-03-30 20:08:47.000000000 +0000
+++ sc/source/filter/inc/xlroot.hxx
@@ -269,7 +269,7 @@ public:
     inline void         IncCurrScTab() { ++mrData.mnScTab; }
 
 private:
-    mutable XclRootData& mrData;        /// Reference to the global data struct.
+    XclRootData& mrData;        /// Reference to the global data struct.
 };
 
 // ============================================================================
