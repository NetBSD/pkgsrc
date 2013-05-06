$NetBSD: patch-sql_sql__bitmap.h,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_bitmap.h.orig	2013-05-05 20:53:40.000000000 +0000
+++ sql/sql_bitmap.h
@@ -60,7 +60,7 @@ public:
     intersect(map2buff);
     if (map.n_bits > sizeof(ulonglong) * 8)
       bitmap_set_above(&map, sizeof(ulonglong),
-                       test(map2buff & (LL(1) << (sizeof(ulonglong) * 8 - 1))));
+                       my_test(map2buff & (LL(1) << (sizeof(ulonglong) * 8 - 1))));
   }
   void subtract(const Bitmap& map2) { bitmap_subtract(&map, &map2.map); }
   void merge(const Bitmap& map2) { bitmap_union(&map, &map2.map); }
@@ -135,7 +135,7 @@ public:
   void intersect_extended(ulonglong map2) { map&= map2; }
   void subtract(const Bitmap<64>& map2) { map&= ~map2.map; }
   void merge(const Bitmap<64>& map2) { map|= map2.map; }
-  my_bool is_set(uint n) const { return test(map & (((ulonglong)1) << n)); }
+  my_bool is_set(uint n) const { return my_test(map & (((ulonglong)1) << n)); }
   my_bool is_prefix(uint n) const { return map == (((ulonglong)1) << n)-1; }
   my_bool is_clear_all() const { return map == (ulonglong)0; }
   my_bool is_set_all() const { return map == ~(ulonglong)0; }
