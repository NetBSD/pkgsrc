$NetBSD: patch-akonadi_resourcebase.h,v 1.1 2016/01/10 19:33:04 markd Exp $

kdepimlibs4-bug338658-[12].patch
https://quickgit.kde.org/?p=kdepimlibs.git&a=commitdiff&h=4429619&o=plain
https://quickgit.kde.org/?p=kdepimlibs.git&a=commitdiff&h=d8b5da7&o=plain
 
--- akonadi/resourcebase.h.orig	2015-06-24 12:43:14.000000000 +0000
+++ akonadi/resourcebase.h
@@ -530,6 +530,20 @@ protected:
     void setItemTransactionMode(ItemSync::TransactionMode mode);
 
     /**
+     * Set merge mode for item sync'ing.
+     *
+     * Default merge mode is RIDMerge.
+     *
+     * @note This method must be called before first call to itemRetrieved(),
+     * itemsRetrieved() or itemsRetrievedIncremental().
+     *
+     * @param mode Item merging mode (see ItemCreateJob for details on item merging)
+     * @see Akonadi::ItemSync::MergeMode
+     * @ince 4.14.11
+     */
+    void setItemMergingMode(ItemSync::MergeMode mode);
+
+    /**
      * Set the fetch scope applied for item synchronization.
      * By default, the one set on the changeRecorder() is used. However, it can make sense
      * to specify a specialized fetch scope for synchronization to improve performance.
