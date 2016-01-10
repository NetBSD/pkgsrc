$NetBSD: patch-akonadi_itemsync.h,v 1.1 2016/01/10 19:33:04 markd Exp $

kdepimlibs4-bug338658-[12].patch
https://quickgit.kde.org/?p=kdepimlibs.git&a=commitdiff&h=4429619&o=plain
https://quickgit.kde.org/?p=kdepimlibs.git&a=commitdiff&h=d8b5da7&o=plain
 
--- akonadi/itemsync.h.orig	2015-06-24 12:43:14.000000000 +0000
+++ akonadi/itemsync.h
@@ -56,6 +56,12 @@ class AKONADI_EXPORT ItemSync : public J
     Q_OBJECT
 
 public:
+    enum MergeMode
+    {
+        RIDMerge,
+        GIDMerge
+    };
+
     /**
      * Creates a new item synchronizer.
      *
@@ -209,6 +215,27 @@ public:
      */
     void setDisableAutomaticDeliveryDone(bool disable);
 
+    /**
+     * Returns current merge mode
+     *
+     * @see setMergeMode()
+     * @since 5.1
+     */
+    MergeMode mergeMode() const;
+
+    /**
+     * Set what merge method should be used for next ItemSync run
+     *
+     * By default ItemSync uses RIDMerge method.
+     *
+     * See ItemCreateJob for details on Item merging.
+     *
+     * @note You must call this method before starting the sync, changes afterwards lead to undefined results.
+     * @see mergeMode
+     * @since 4.14.11
+     */
+    void setMergeMode(MergeMode mergeMode);
+
 Q_SIGNALS:
     /**
      * Signals the resource that new items can be delivered.
