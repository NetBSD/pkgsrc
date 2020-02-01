$NetBSD: patch-src_mongo_db_query_collation_collator__interface__icu.h,v 1.1 2020/02/01 20:00:08 adam Exp $

Fix for newer ICU.

--- src/mongo/db/query/collation/collator_interface_icu.h.orig	2020-01-26 09:25:13.000000000 +0000
+++ src/mongo/db/query/collation/collator_interface_icu.h
@@ -33,9 +33,7 @@
 
 #include <memory>
 
-namespace icu {
-class Collator;
-}  // namespace icu
+#include <unicode/coll.h>
 
 namespace mongo {
 
@@ -45,7 +43,7 @@ namespace mongo {
  */
 class CollatorInterfaceICU final : public CollatorInterface {
 public:
-    CollatorInterfaceICU(CollationSpec spec, std::unique_ptr<icu::Collator> collator);
+    CollatorInterfaceICU(CollationSpec spec, std::unique_ptr<U_ICU_NAMESPACE::Collator> collator);
 
     std::unique_ptr<CollatorInterface> clone() const final;
 
@@ -56,7 +54,7 @@ public:
 private:
     // The ICU implementation of the collator to which we delegate interesting work. Const methods
     // on the ICU collator are expected to be thread-safe.
-    const std::unique_ptr<icu::Collator> _collator;
+    const std::unique_ptr<U_ICU_NAMESPACE::Collator> _collator;
 };
 
 }  // namespace mongo
