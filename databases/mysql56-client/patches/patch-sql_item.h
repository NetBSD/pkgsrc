$NetBSD: patch-sql_item.h,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/item.h.orig	2013-05-05 20:52:25.000000000 +0000
+++ sql/item.h
@@ -1637,7 +1637,7 @@ public:
   {
     if (is_expensive_cache < 0)
       is_expensive_cache= walk(&Item::is_expensive_processor, 0, (uchar*)0);
-    return test(is_expensive_cache);
+    return my_test(is_expensive_cache);
   }
   virtual bool can_be_evaluated_now() const;
   uint32 max_char_length() const
@@ -2578,7 +2578,7 @@ public:
   virtual void print(String *str, enum_query_type query_type);
   Item_num *neg() { value= -value; return this; }
   uint decimal_precision() const
-  { return (uint)(max_length - test(value < 0)); }
+  { return (uint)(max_length - my_test(value < 0)); }
   bool eq(const Item *, bool binary_cmp) const;
   bool check_partition_func_processor(uchar *bool_arg) { return FALSE;}
 };
@@ -4168,7 +4168,7 @@ public:
   virtual void store(Item *item);
   virtual bool cache_value()= 0;
   bool basic_const_item() const
-  { return test(example && example->basic_const_item());}
+  { return my_test(example && example->basic_const_item());}
   bool walk (Item_processor processor, bool walk_subquery, uchar *argument);
   virtual void clear() { null_value= TRUE; value_cached= FALSE; }
   bool is_null() { return value_cached ? null_value : example->is_null(); }
