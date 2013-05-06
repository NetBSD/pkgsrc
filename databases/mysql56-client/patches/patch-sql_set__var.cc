$NetBSD: patch-sql_set__var.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/set_var.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/set_var.cc
@@ -566,7 +566,7 @@ int sql_set_variables(THD *thd, List<set
     if ((error= var->check(thd)))
       goto err;
   }
-  if (!(error= test(thd->is_error())))
+  if (!(error= my_test(thd->is_error())))
   {
     it.rewind();
     while ((var= it++))
