$NetBSD: patch-src_torrent_utils_extents.h,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/torrent/utils/extents.h.orig	2012-02-24 06:24:02.000000000 +0000
+++ src/torrent/utils/extents.h
@@ -37,7 +37,13 @@
 #ifndef LIBTORRENT_UTILS_EXTENTS_H
 #define LIBTORRENT_UTILS_EXTENTS_H
 
+#if __cplusplus >= 201103L
+#include <array>
+using std::array;
+#else
 #include <tr1/array>
+using std::tr1::array;
+#endif
 
 namespace torrent {
 
@@ -48,12 +54,24 @@ struct extents_base {
   typedef std::pair<extents_base*, Tp> mapped_type;
   typedef Tp                           mapped_value_type;
 
-  typedef std::tr1::array<mapped_type, TableSize> table_type;
+  typedef array<mapped_type, TableSize> table_type;
   
   extents_base(key_type pos, unsigned int mb, mapped_value_type val) :
-    mask_bits(mb), position(pos) { table.assign(mapped_type(NULL, mapped_value_type())); }
+    mask_bits(mb), position(pos) {
+#if __cplusplus >= 201103L
+     table.fill(mapped_type(NULL, mapped_value_type()));
+#else
+     table.assign(mapped_type(NULL, mapped_value_type()));
+#endif
+   }
   extents_base(extents_base* parent, typename table_type::const_iterator itr) :
-    mask_bits(parent->mask_bits - TableBits), position(parent->partition_pos(itr)) { table.assign(mapped_type(NULL, itr->second)); }
+    mask_bits(parent->mask_bits - TableBits), position(parent->partition_pos(itr)) {
+#if __cplusplus >= 201103L
+     table.fill(mapped_type(NULL, itr->second));
+#else
+     table.assign(mapped_type(NULL, itr->second));
+#endif
+  }
   ~extents_base();
 
   bool         is_divisible(key_type key) const { return key % mask_bits == 0; }
