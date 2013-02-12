$NetBSD: patch-tools_build_v2_engine_hash.c,v 1.3 2013/02/12 21:07:22 adam Exp $

Fix alignement for 32bit platforms with alignment restrictions.
A time_t requires greater alignement than a void*.

--- tools/build/v2/engine/hash.c.orig	2013-01-16 16:21:53.000000000 +0100
+++ tools/build/v2/engine/hash.c	2013-01-17 12:36:56.000000000 +0100
@@ -34,7 +34,17 @@
 
 struct hashhdr
 {
-    struct item  * next;
+    union {
+        struct item  * next;
+	/*
+	 * Some architectures have 32bit pointers but 64bit time_t (as used
+	 * in file_info_t), and require natural alignement of data.
+	 * Since we offset an aligned pointer by sizeof(hashhdr) in
+	 * hash_item_data(item), we may cause misalignement if we do not
+	 * make sure that sizeof(hashhdr) is properly aligned.
+	 */
+	time_t aligner;	/* unused dummy for alignement */
+    } h;
 };
 
 typedef struct item
@@ -106,7 +116,7 @@ static ITEM * hash_search(
     ITEM * i = *hash_bucket(hp,keyval);
     ITEM * p = 0;
 
-    for ( ; i; i = i->hdr.next )
+    for ( ; i; i = i->hdr.h.next )
     {
         if ( object_equal( hash_item_key( i ), keydata ) )
         {
@@ -153,7 +163,7 @@ HASHDATA * hash_insert( struct hash * hp
         if ( hp->items.free )
         {
             i = hp->items.free;
-            hp->items.free = i->hdr.next;
+            hp->items.free = i->hdr.h.next;
             assert( hash_item_key( i ) == 0 );
         }
         else
@@ -162,7 +172,7 @@ HASHDATA * hash_insert( struct hash * hp
             hp->items.next += hp->items.size;
         }
         hp->items.more--;
-        i->hdr.next = *base;
+        i->hdr.h.next = *base;
         *base = i;
         *found = 0;
     }
@@ -251,7 +261,7 @@ static void hashrehash( register struct 
             /* code currently assumes rehashing only when there are no free items */
             assert( hash_item_key( i ) != 0 );
 
-            i->hdr.next = *ip;
+            i->hdr.h.next = *ip;
             *ip = i;
         }
     }
@@ -367,7 +377,7 @@ void hashstats_add( struct hashstats * s
         {
             ITEM * item;
             int here = 0;
-            for ( item = tab[ i ]; item != 0; item = item->hdr.next )
+            for ( item = tab[ i ]; item != 0; item = item->hdr.h.next )
                 ++here;
 
             count += here;
