$NetBSD: patch-sql_unireg.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/unireg.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/unireg.cc
@@ -287,7 +287,7 @@ bool mysql_create_frm(THD *thd, const ch
   maxlength=(uint) next_io_size((ulong) (uint2korr(forminfo_p)+1000));
   int2store(forminfo+2,maxlength);
   int4store(fileinfo+10,(ulong) (filepos+maxlength));
-  fileinfo[26]= (uchar) test((create_info->max_rows == 1) &&
+  fileinfo[26]= (uchar) my_test((create_info->max_rows == 1) &&
 			     (create_info->min_rows == 1) && (keys == 0));
   int2store(fileinfo+28,key_info_length);
 
