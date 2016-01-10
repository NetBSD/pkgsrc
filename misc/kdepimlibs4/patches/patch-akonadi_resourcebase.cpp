$NetBSD: patch-akonadi_resourcebase.cpp,v 1.1 2016/01/10 19:33:04 markd Exp $

kdepimlibs4-bug338658-[12].patch
https://quickgit.kde.org/?p=kdepimlibs.git&a=commitdiff&h=4429619&o=plain
https://quickgit.kde.org/?p=kdepimlibs.git&a=commitdiff&h=d8b5da7&o=plain

--- akonadi/resourcebase.cpp.orig	2015-06-24 12:43:14.000000000 +0000
+++ akonadi/resourcebase.cpp
@@ -75,6 +75,7 @@ public:
         , mItemSyncer(0)
         , mItemSyncFetchScope(0)
         , mItemTransactionMode(ItemSync::SingleTransaction)
+        , mItemMergeMode(ItemSync::RIDMerge)
         , mCollectionSyncer(0)
         , mHierarchicalRid(false)
         , mUnemittedProgress(0)
@@ -179,6 +180,7 @@ public:
             mItemSyncer = new ItemSync(q->currentCollection());
             mItemSyncer->setTransactionMode(mItemTransactionMode);
             mItemSyncer->setBatchSize(mItemSyncBatchSize);
+            mItemSyncer->setMergeMode(mItemMergeMode);
             if (mItemSyncFetchScope) {
                 mItemSyncer->setFetchScope(*mItemSyncFetchScope);
             }
@@ -448,6 +450,7 @@ public:
     ItemSync *mItemSyncer;
     ItemFetchScope *mItemSyncFetchScope;
     ItemSync::TransactionMode mItemTransactionMode;
+    ItemSync::MergeMode mItemMergeMode;
     CollectionSync *mCollectionSyncer;
     bool mHierarchicalRid;
     QTimer mProgressEmissionCompressor;
@@ -1314,6 +1317,12 @@ void ResourceBase::setItemSynchronizatio
     *(d->mItemSyncFetchScope) = fetchScope;
 }
 
+void ResourceBase::setItemMergingMode(ItemSync::MergeMode mode)
+{
+    Q_D(ResourceBase);
+    d->mItemMergeMode = mode;
+}
+
 void ResourceBase::setAutomaticProgressReporting(bool enabled)
 {
     Q_D(ResourceBase);
