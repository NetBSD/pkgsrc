$NetBSD: patch-sql_transaction.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/transaction.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/transaction.cc
@@ -134,7 +134,7 @@ bool trans_begin(THD *thd, uint flags)
     thd->server_status&=
       ~(SERVER_STATUS_IN_TRANS | SERVER_STATUS_IN_TRANS_READONLY);
     DBUG_PRINT("info", ("clearing SERVER_STATUS_IN_TRANS"));
-    res= test(ha_commit_trans(thd, TRUE));
+    res= my_test(ha_commit_trans(thd, TRUE));
   }
 
   thd->variables.option_bits&= ~OPTION_BEGIN;
@@ -163,7 +163,7 @@ bool trans_begin(THD *thd, uint flags)
       compatibility.
     */
     const bool user_is_super=
-      test(thd->security_ctx->master_access & SUPER_ACL);
+      my_test(thd->security_ctx->master_access & SUPER_ACL);
     if (opt_readonly && !user_is_super)
     {
       my_error(ER_OPTION_PREVENTS_STATEMENT, MYF(0), "--read-only");
@@ -182,7 +182,7 @@ bool trans_begin(THD *thd, uint flags)
   if (flags & MYSQL_START_TRANS_OPT_WITH_CONS_SNAPSHOT)
     res= ha_start_consistent_snapshot(thd);
 
-  DBUG_RETURN(test(res));
+  DBUG_RETURN(my_test(res));
 }
 
 
@@ -221,7 +221,7 @@ bool trans_commit(THD *thd)
   thd->transaction.all.reset_unsafe_rollback_flags();
   thd->lex->start_transaction_opt= 0;
 
-  DBUG_RETURN(test(res));
+  DBUG_RETURN(my_test(res));
 }
 
 
@@ -263,7 +263,7 @@ bool trans_commit_implicit(THD *thd)
     thd->server_status&=
       ~(SERVER_STATUS_IN_TRANS | SERVER_STATUS_IN_TRANS_READONLY);
     DBUG_PRINT("info", ("clearing SERVER_STATUS_IN_TRANS"));
-    res= test(ha_commit_trans(thd, TRUE));
+    res= my_test(ha_commit_trans(thd, TRUE));
   }
   else if (tc_log)
     tc_log->commit(thd, true);
@@ -319,7 +319,7 @@ bool trans_rollback(THD *thd)
   thd->transaction.all.reset_unsafe_rollback_flags();
   thd->lex->start_transaction_opt= 0;
 
-  DBUG_RETURN(test(res));
+  DBUG_RETURN(my_test(res));
 }
 
 
@@ -382,7 +382,7 @@ bool trans_commit_stmt(THD *thd)
 
   thd->transaction.stmt.reset();
 
-  DBUG_RETURN(test(res));
+  DBUG_RETURN(my_test(res));
 }
 
 
@@ -588,7 +588,7 @@ bool trans_rollback_to_savepoint(THD *th
   if (!res && !binlog_on)
     thd->mdl_context.rollback_to_savepoint(sv->mdl_savepoint);
 
-  DBUG_RETURN(test(res));
+  DBUG_RETURN(my_test(res));
 }
 
 
@@ -630,7 +630,7 @@ bool trans_release_savepoint(THD *thd, L
 
   thd->transaction.savepoints= sv->prev;
 
-  DBUG_RETURN(test(res));
+  DBUG_RETURN(my_test(res));
 }
 
 
@@ -794,7 +794,7 @@ bool trans_xa_commit(THD *thd)
   else if (xa_state == XA_IDLE && thd->lex->xa_opt == XA_ONE_PHASE)
   {
     int r= ha_commit_trans(thd, TRUE);
-    if ((res= test(r)))
+    if ((res= my_test(r)))
       my_error(r == 1 ? ER_XA_RBROLLBACK : ER_XAER_RMERR, MYF(0));
   }
   else if (xa_state == XA_PREPARED && thd->lex->xa_opt == XA_NONE)
@@ -822,9 +822,9 @@ bool trans_xa_commit(THD *thd)
       DEBUG_SYNC(thd, "trans_xa_commit_after_acquire_commit_lock");
 
       if (tc_log)
-        res= test(tc_log->commit(thd, /* all */ true));
+        res= my_test(tc_log->commit(thd, /* all */ true));
       else
-        res= test(ha_commit_low(thd, /* all */ true));
+        res= my_test(ha_commit_low(thd, /* all */ true));
 
       if (res)
         my_error(ER_XAER_RMERR, MYF(0));
