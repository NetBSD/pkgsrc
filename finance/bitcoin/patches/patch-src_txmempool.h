$NetBSD: patch-src_txmempool.h,v 1.1 2026/05/15 09:32:41 adam Exp $

Fix compilation failure with boost >= 1.91
https://github.com/bitcoin/bitcoin/pull/35175

--- src/txmempool.h.orig	2026-05-04 13:59:18.096188699 +0000
+++ src/txmempool.h
@@ -211,7 +211,9 @@ public:
 
     static const int ROLLING_FEE_HALFLIFE = 60 * 60 * 12; // public only for testing
 
-    struct CTxMemPoolEntry_Indices final : boost::multi_index::indexed_by<
+    using indexed_transaction_set = boost::multi_index_container<
+        CTxMemPoolEntry,
+        boost::multi_index::indexed_by<
             // sorted by txid
             boost::multi_index::hashed_unique<mempoolentry_txid, SaltedTxidHasher>,
             // sorted by wtxid
@@ -227,11 +229,7 @@ public:
                 CompareTxMemPoolEntryByEntryTime
             >
         >
-        {};
-    typedef boost::multi_index_container<
-        CTxMemPoolEntry,
-        CTxMemPoolEntry_Indices
-    > indexed_transaction_set;
+    >;
 
     /**
      * This mutex needs to be locked when accessing `mapTx` or other members
