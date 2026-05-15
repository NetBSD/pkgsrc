$NetBSD: patch-src_txrequest.cpp,v 1.1 2026/05/15 09:32:41 adam Exp $

Fix compilation failure with boost >= 1.91
https://github.com/bitcoin/bitcoin/pull/35175

--- src/txrequest.cpp.orig	2026-04-15 20:55:24.000000000 +0000
+++ src/txrequest.cpp
@@ -208,17 +208,15 @@ struct ByTimeViewExtractor
     }
 };
 
-struct Announcement_Indices final : boost::multi_index::indexed_by<
-    boost::multi_index::ordered_unique<boost::multi_index::tag<ByPeer>, ByPeerViewExtractor>,
-    boost::multi_index::ordered_non_unique<boost::multi_index::tag<ByTxHash>, ByTxHashViewExtractor>,
-    boost::multi_index::ordered_non_unique<boost::multi_index::tag<ByTime>, ByTimeViewExtractor>
->
-{};
 
 /** Data type for the main data structure (Announcement objects with ByPeer/ByTxHash/ByTime indexes). */
 using Index = boost::multi_index_container<
     Announcement,
-    Announcement_Indices
+    boost::multi_index::indexed_by<
+        boost::multi_index::ordered_unique<boost::multi_index::tag<ByPeer>, ByPeerViewExtractor>,
+        boost::multi_index::ordered_non_unique<boost::multi_index::tag<ByTxHash>, ByTxHashViewExtractor>,
+        boost::multi_index::ordered_non_unique<boost::multi_index::tag<ByTime>, ByTimeViewExtractor>
+    >
 >;
 
 /** Helper type to simplify syntax of iterator types. */
