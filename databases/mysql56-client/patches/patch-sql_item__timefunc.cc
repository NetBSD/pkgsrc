$NetBSD: patch-sql_item__timefunc.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/item_timefunc.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/item_timefunc.cc
@@ -1337,7 +1337,7 @@ longlong Item_func_weekday::val_int()
 
   return (longlong) calc_weekday(calc_daynr(ltime.year, ltime.month,
                                             ltime.day),
-                                 odbc_type) + test(odbc_type);
+                                 odbc_type) + my_test(odbc_type);
 }
 
 void Item_func_dayname::fix_length_and_dec()
