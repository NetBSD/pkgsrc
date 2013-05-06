$NetBSD: patch-storage_federated_ha__federated.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- storage/federated/ha_federated.cc.orig	2013-05-05 20:50:46.000000000 +0000
+++ storage/federated/ha_federated.cc
@@ -1463,7 +1463,7 @@ prepare_for_next_key_part:
         ptr was incremented by 1. Since store_length still counts null-byte,
         we need to subtract 1 from store_length.
       */
-      ptr+= store_length - test(key_part->null_bit);
+      ptr+= store_length - my_test(key_part->null_bit);
       if (tmp.append(STRING_WITH_LEN(" AND ")))
         goto err;
 
@@ -2105,7 +2105,7 @@ int ha_federated::update_row(const uchar
     this? Because we only are updating one record, and LIMIT enforces
     this.
   */
-  bool has_a_primary_key= test(table->s->primary_key != MAX_KEY);
+  bool has_a_primary_key= my_test(table->s->primary_key != MAX_KEY);
   
   /*
     buffers for following strings
