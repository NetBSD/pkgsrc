$NetBSD: patch-src_CSqlTable.cpp,v 1.1 2014/02/22 14:14:01 wiedi Exp $

fix "pow(int) is ambigous" on SunOS
--- src/CSqlTable.cpp.orig	2006-08-11 20:29:12.000000000 +0000
+++ src/CSqlTable.cpp
@@ -688,7 +688,7 @@ char * CSqlTable::getWhereClause(int row
       {
         len += field->length() + 1;
         if (field->isPresision())
-          len += 10 + QString::number(pow(0.1, field->decimals())).length();
+          len += 10 + QString::number(pow(0.1, (double)field->decimals())).length();
       }
       else
         len_tmp += field->length() * 2 + 4;
@@ -711,7 +711,7 @@ char * CSqlTable::getWhereClause(int row
     
     if (field->isPresision())
     {
-      QString tmp = "ABS(" + it.data() + " - " + field->value() + ") < " + QString::number(pow(0.1, field->decimals()));
+      QString tmp = "ABS(" + it.data() + " - " + field->value() + ") < " + QString::number(pow(0.1, (double)field->decimals()));
       end_ptr = strmov(end_ptr, (const char *)(mysql()->mysql()->codec()->fromUnicode(tmp)));      
     }
     else
