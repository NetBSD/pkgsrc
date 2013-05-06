$NetBSD: patch-sql_sql__table.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_table.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sql_table.cc
@@ -3870,7 +3870,7 @@ mysql_prepare_create_table(THD *thd, HA_
 	  with length (unlike blobs, where ft code takes data length from a
 	  data prefix, ignoring column->length).
 	*/
-	column->length=test(f_is_blob(sql_field->pack_flag));
+	column->length=my_test(f_is_blob(sql_field->pack_flag));
       }
       else
       {
@@ -7012,7 +7012,7 @@ mysql_prepare_alter_table(THD *thd, TABL
 
       key= new Key(key_type, key_name, strlen(key_name),
                    &key_create_info,
-                   test(key_info->flags & HA_GENERATED_KEY),
+                   my_test(key_info->flags & HA_GENERATED_KEY),
                    key_parts);
       new_key_list.push_back(key);
     }
@@ -9029,7 +9029,7 @@ static bool check_engine(THD *thd, const
   handlerton **new_engine= &create_info->db_type;
   handlerton *req_engine= *new_engine;
   bool no_substitution=
-        test(thd->variables.sql_mode & MODE_NO_ENGINE_SUBSTITUTION);
+        my_test(thd->variables.sql_mode & MODE_NO_ENGINE_SUBSTITUTION);
   if (!(*new_engine= ha_checktype(thd, ha_legacy_type(req_engine),
                                   no_substitution, 1)))
     DBUG_RETURN(true);
