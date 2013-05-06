$NetBSD: patch-sql_sql__acl.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_acl.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sql_acl.cc
@@ -2732,9 +2732,9 @@ update_user_table(THD *thd, TABLE *table
 static bool test_if_create_new_users(THD *thd)
 {
   Security_context *sctx= thd->security_ctx;
-  bool create_new_users= test(sctx->master_access & INSERT_ACL) ||
+  bool create_new_users= my_test(sctx->master_access & INSERT_ACL) ||
                          (!opt_safe_user_create &&
-                          test(sctx->master_access & CREATE_USER_ACL));
+                          my_test(sctx->master_access & CREATE_USER_ACL));
   if (!create_new_users)
   {
     TABLE_LIST tl;
@@ -4449,7 +4449,7 @@ int mysql_table_grant(THD *thd, TABLE_LI
     /* Create user if needed */
     error=replace_user_table(thd, tables[0].table, Str,
 			     0, revoke_grant, create_new_users,
-                             test(thd->variables.sql_mode &
+                             my_test(thd->variables.sql_mode &
                                   MODE_NO_AUTO_CREATE_USER));
     if (error)
     {
@@ -4694,7 +4694,7 @@ bool mysql_routine_grant(THD *thd, TABLE
     /* Create user if needed */
     error=replace_user_table(thd, tables[0].table, Str,
 			     0, revoke_grant, create_new_users,
-                             test(thd->variables.sql_mode &
+                             my_test(thd->variables.sql_mode &
                                   MODE_NO_AUTO_CREATE_USER));
     if (error)
     {
@@ -4971,7 +4971,7 @@ bool mysql_grant(THD *thd, const char *d
  
     if (replace_user_table(thd, tables[0].table, Str,
                            (!db ? rights : 0), revoke_grant, create_new_users,
-                           test(thd->variables.sql_mode &
+                           my_test(thd->variables.sql_mode &
                                 MODE_NO_AUTO_CREATE_USER)))
       result= -1;
     else if (db)
@@ -5470,7 +5470,7 @@ bool check_grant(THD *thd, ulong want_ac
        tl && number-- && tl != first_not_own_table;
        tl= tl->next_global)
   {
-    sctx = test(tl->security_ctx) ? tl->security_ctx : thd->security_ctx;
+    sctx = my_test(tl->security_ctx) ? tl->security_ctx : thd->security_ctx;
 
     const ACL_internal_table_access *access=
       get_cached_table_access(&tl->grant.m_internal,
@@ -5680,7 +5680,7 @@ bool check_column_grant_in_table_ref(THD
   GRANT_INFO *grant;
   const char *db_name;
   const char *table_name;
-  Security_context *sctx= test(table_ref->security_ctx) ?
+  Security_context *sctx= my_test(table_ref->security_ctx) ?
                           table_ref->security_ctx : thd->security_ctx;
 
   if (table_ref->view || table_ref->field_translation)
