$NetBSD: patch-akonadi_itemsync.cpp,v 1.1 2016/01/10 19:33:04 markd Exp $

kdepimlibs4-bug338658-[12].patch
https://quickgit.kde.org/?p=kdepimlibs.git&a=commitdiff&h=4429619&o=plain
https://quickgit.kde.org/?p=kdepimlibs.git&a=commitdiff&h=d8b5da7&o=plain

--- akonadi/itemsync.cpp.orig	2016-01-08 23:32:29.000000000 +0000
+++ akonadi/itemsync.cpp
@@ -61,6 +61,7 @@ public:
         , mProcessingBatch(false)
         , mDisableAutomaticDeliveryDone(false)
         , mBatchSize(10)
+        , mMergeMode(Akonadi::ItemSync::RIDMerge)
     {
         // we want to fetch all data by default
         mFetchScope.fetchFullPayload();
@@ -116,6 +117,7 @@ public:
     bool mDisableAutomaticDeliveryDone;
 
     int mBatchSize;
+    Akonadi::ItemSync::MergeMode mMergeMode;
 };
 
 void ItemSyncPrivate::createOrMerge(const Item &item)
@@ -127,11 +129,13 @@ void ItemSyncPrivate::createOrMerge(cons
     }
     mPendingJobs++;
     ItemCreateJob *create = new ItemCreateJob(item, mSyncCollection, subjobParent());
-    if (!item.gid().isEmpty()) {
-        create->setMerge(ItemCreateJob::GID|ItemCreateJob::Silent);
+    ItemCreateJob::MergeOptions merge = ItemCreateJob::Silent;
+    if (mMergeMode == ItemSync::GIDMerge && !item.gid().isEmpty()) {
+        merge |= ItemCreateJob::GID;
     } else {
-        create->setMerge(ItemCreateJob::RID|ItemCreateJob::Silent);
+        merge |= ItemCreateJob::RID;
     }
+    create->setMerge(merge);
     q->connect(create, SIGNAL(result(KJob*)), q, SLOT(slotLocalChangeDone(KJob*)));
 }
 
@@ -534,5 +538,16 @@ void ItemSync::setBatchSize(int size)
     d->mBatchSize = size;
 }
 
+ItemSync::MergeMode ItemSync::mergeMode() const
+{
+    Q_D(const ItemSync);
+    return d->mMergeMode;
+}
+
+void ItemSync::setMergeMode(MergeMode mergeMode)
+{
+    Q_D(ItemSync);
+    d->mMergeMode = mergeMode;
+}
 
 #include "moc_itemsync.cpp"
