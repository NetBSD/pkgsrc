$NetBSD: patch-storage_heap_hp__hash.c,v 1.1 2013/04/29 21:16:57 joerg Exp $

--- storage/heap/hp_hash.c.orig	2013-04-28 13:58:16.000000000 +0000
+++ storage/heap/hp_hash.c
@@ -596,7 +596,7 @@ int hp_key_cmp(HP_KEYDEF *keydef, const 
   {
     if (seg->null_bit)
     {
-      int found_null=test(rec[seg->null_pos] & seg->null_bit);
+      int found_null=my_test(rec[seg->null_pos] & seg->null_bit);
       if (found_null != (int) *key++)
 	return 1;
       if (found_null)
@@ -684,7 +684,7 @@ void hp_make_key(HP_KEYDEF *keydef, ucha
     uint char_length= seg->length;
     uchar *pos= (uchar*) rec + seg->start;
     if (seg->null_bit)
-      *key++= test(rec[seg->null_pos] & seg->null_bit);
+      *key++= my_test(rec[seg->null_pos] & seg->null_bit);
     if (cs->mbmaxlen > 1)
     {
       char_length= my_charpos(cs, pos, pos + seg->length,
@@ -717,7 +717,7 @@ uint hp_rb_make_key(HP_KEYDEF *keydef, u
     uint char_length;
     if (seg->null_bit)
     {
-      if (!(*key++= 1 - test(rec[seg->null_pos] & seg->null_bit)))
+      if (!(*key++= 1 - my_test(rec[seg->null_pos] & seg->null_bit)))
         continue;
     }
     if (seg->flag & HA_SWAP_KEY)
