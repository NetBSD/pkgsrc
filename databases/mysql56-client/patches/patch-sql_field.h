$NetBSD: patch-sql_field.h,v 1.2 2013/07/31 09:51:38 adam Exp $

--- sql/field.h.orig	2013-07-10 16:17:27.000000000 +0000
+++ sql/field.h
@@ -891,14 +891,14 @@ public:
 
     */
     return real_maybe_null() ?
-      test(null_ptr[row_offset] & null_bit) : table->null_row;
+      my_test(null_ptr[row_offset] & null_bit) : table->null_row;
   }
 
   bool is_real_null(my_ptrdiff_t row_offset= 0) const
-  { return real_maybe_null() ? test(null_ptr[row_offset] & null_bit) : false; }
+  { return real_maybe_null() ? my_test(null_ptr[row_offset] & null_bit) : false; }
 
   bool is_null_in_record(const uchar *record) const
-  { return real_maybe_null() ? test(record[null_offset()] & null_bit) : false; }
+  { return real_maybe_null() ? my_test(record[null_offset()] & null_bit) : false; }
 
   void set_null(my_ptrdiff_t row_offset= 0)
   {
@@ -3670,9 +3670,9 @@ public:
   {
     DBUG_ASSERT(ptr == a || ptr == b);
     if (ptr == a)
-      return Field_bit::key_cmp(b, bytes_in_rec+test(bit_len));
+      return Field_bit::key_cmp(b, bytes_in_rec+my_test(bit_len));
     else
-      return Field_bit::key_cmp(a, bytes_in_rec+test(bit_len)) * -1;
+      return Field_bit::key_cmp(a, bytes_in_rec+my_test(bit_len)) * -1;
   }
   int cmp_binary_offset(uint row_offset)
   { return cmp_offset(row_offset); }
