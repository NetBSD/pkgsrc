$NetBSD: patch-sql_sql__show.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_show.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sql_show.cc
@@ -740,7 +740,7 @@ public:
     m_view_access_denied_message_ptr(NULL) 
   {
     
-    m_sctx = test(m_top_view->security_ctx) ?
+    m_sctx = my_test(m_top_view->security_ctx) ?
       m_top_view->security_ctx : thd->security_ctx;
   }
 
@@ -1835,7 +1835,7 @@ static void store_key_options(THD *thd, 
       end= longlong10_to_str(key_info->block_size, buff, 10);
       packet->append(buff, (uint) (end - buff));
     }
-    DBUG_ASSERT(test(key_info->flags & HA_USES_COMMENT) == 
+    DBUG_ASSERT(my_test(key_info->flags & HA_USES_COMMENT) == 
                (key_info->comment.length > 0));
     if (key_info->flags & HA_USES_COMMENT)
     {
@@ -4634,7 +4634,7 @@ static int get_schema_column_record(THD 
 #ifndef NO_EMBEDDED_ACCESS_CHECKS
     uint col_access;
     check_access(thd,SELECT_ACL, db_name->str,
-                 &tables->grant.privilege, 0, 0, test(tables->schema_table));
+                 &tables->grant.privilege, 0, 0, my_test(tables->schema_table));
     col_access= get_column_grant(thd, &tables->grant,
                                  db_name->str, table_name->str,
                                  field->field_name) & COL_ACLS;
@@ -4775,13 +4775,13 @@ static my_bool iter_schema_engines(THD *
       table->field[1]->store(option_name, strlen(option_name), scs);
       table->field[2]->store(plugin_decl(plugin)->descr,
                              strlen(plugin_decl(plugin)->descr), scs);
-      tmp= &yesno[test(hton->commit)];
+      tmp= &yesno[my_test(hton->commit)];
       table->field[3]->store(tmp->str, tmp->length, scs);
       table->field[3]->set_notnull();
-      tmp= &yesno[test(hton->prepare)];
+      tmp= &yesno[my_test(hton->prepare)];
       table->field[4]->store(tmp->str, tmp->length, scs);
       table->field[4]->set_notnull();
-      tmp= &yesno[test(hton->savepoint_set)];
+      tmp= &yesno[my_test(hton->savepoint_set)];
       table->field[5]->store(tmp->str, tmp->length, scs);
       table->field[5]->set_notnull();
 
@@ -5357,7 +5357,7 @@ static int get_schema_stat_record(THD *t
         else
           table->field[14]->store("", 0, cs);
         table->field[14]->set_notnull();
-        DBUG_ASSERT(test(key_info->flags & HA_USES_COMMENT) == 
+        DBUG_ASSERT(my_test(key_info->flags & HA_USES_COMMENT) == 
                    (key_info->comment.length > 0));
         if (key_info->flags & HA_USES_COMMENT)
           table->field[15]->store(key_info->comment.str, 
