$NetBSD: patch-src_node_txorphanage.cpp,v 1.1 2026/05/15 09:32:41 adam Exp $

Fix compilation failure with boost >= 1.91
https://github.com/bitcoin/bitcoin/pull/35175

--- src/node/txorphanage.cpp.orig	2026-04-15 20:55:24.000000000 +0000
+++ src/node/txorphanage.cpp
@@ -91,12 +91,13 @@ class TxOrphanageImpl final : public TxO
         }
     };
 
-    struct OrphanIndices final : boost::multi_index::indexed_by<
-        boost::multi_index::ordered_unique<boost::multi_index::tag<ByWtxid>, WtxidExtractor>,
-        boost::multi_index::ordered_unique<boost::multi_index::tag<ByPeer>, ByPeerViewExtractor>
-    >{};
-
-    using AnnouncementMap = boost::multi_index::multi_index_container<Announcement, OrphanIndices>;
+    using AnnouncementMap = boost::multi_index::multi_index_container<
+        Announcement,
+        boost::multi_index::indexed_by<
+            boost::multi_index::ordered_unique<boost::multi_index::tag<ByWtxid>, WtxidExtractor>,
+            boost::multi_index::ordered_unique<boost::multi_index::tag<ByPeer>, ByPeerViewExtractor>
+        >
+    >;
     template<typename Tag>
     using Iter = typename AnnouncementMap::index<Tag>::type::iterator;
     AnnouncementMap m_orphans;
