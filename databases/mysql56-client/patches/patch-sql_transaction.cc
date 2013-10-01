$NetBSD: patch-sql_transaction.cc,v 1.2 2013/10/01 10:26:39 adam Exp $

--- sql/transaction.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/transaction.cc
@@ -143,7 +143,7 @@ bool trans_begin(THD *thd, uint flags)
     thd->server_status&=
       ~(SERVER_STATUS_IN_TRANS | SERVER_STATUS_IN_TRANS_READONLY);
     DBUG_PRINT("info", ("clearing SERVER_STATUS_IN_TRANS"));
-    res= test(ha_commit_trans(thd, TRUE));
+    res= my_test(ha_commit_trans(thd, TRUE));
   }
 
   thd->variables.option_bits&= ~OPTION_BEGIN;
@@ -172,7 +172,7 @@ bool trans_begin(THD *thd, uint flags)
       compatibility.
     */
     const bool user_is_super=
-      test(thd->security_ctx->master_access & SUPER_ACL);
+      my_test(thd->security_ctx->master_access & SUPER_ACL);
     if (opt_readonly && !user_is_super)
     {
       my_error(ER_OPTION_PREVENTS_STATEMENT, MYF(0), "--read-only");
@@ -191,7 +191,7 @@ bool trans_begin(THD *thd, uint flags)
   if (flags & MYSQL_START_TRANS_OPT_WITH_CONS_SNAPSHOT)
     res= ha_start_consistent_snapshot(thd);
 
-  DBUG_RETURN(test(res));
+  DBUG_RETURN(my_test(res));
 }
 
 
@@ -230,7 +230,7 @@ bool trans_commit(THD *thd)
   thd->transaction.all.reset_unsafe_rollback_flags();
   thd->lex->start_transaction_opt= 0;
 
-  DBUG_RETURN(test(res));
+  DBUG_RETURN(my_test(res));
 }
 
 
@@ -278,7 +278,7 @@ bool trans_commit_implicit(THD *thd)
     thd->server_status&=
       ~(SERVER_STATUS_IN_TRANS | SERVER_STATUS_IN_TRANS_READONLY);
     DBUG_PRINT("info", ("clearing SERVER_STATUS_IN_TRANS"));
-    res= test(ha_commit_trans(thd, TRUE));
+    res= my_test(ha_commit_trans(thd, TRUE));
   }
   else if (tc_log)
     tc_log->commit(thd, true);
@@ -334,7 +334,7 @@ bool trans_rollback(THD *thd)
   thd->transaction.all.reset_unsafe_rollback_flags();
   thd->lex->start_transaction_opt= 0;
 
-  DBUG_RETURN(test(res));
+  DBUG_RETURN(my_test(res));
 }
 
 
@@ -380,7 +380,7 @@ bool trans_rollback_implicit(THD *thd)
   /* Rollback should clear transaction_rollback_request flag. */
   DBUG_ASSERT(! thd->transaction_rollback_request);
 
-  DBUG_RETURN(test(res));
+  DBUG_RETURN(my_test(res));
 }
 
 
@@ -443,7 +443,7 @@ bool trans_commit_stmt(THD *thd)
 
   thd->transaction.stmt.reset();
 
-  DBUG_RETURN(test(res));
+  DBUG_RETURN(my_test(res));
 }
 
 
@@ -647,7 +647,7 @@ bool trans_rollback_to_savepoint(THD *th
   if (!res && !binlog_on)
     thd->mdl_context.rollback_to_savepoint(sv->mdl_savepoint);
 
-  DBUG_RETURN(test(res));
+  DBUG_RETURN(my_test(res));
 }
 
 
@@ -689,7 +689,7 @@ bool trans_release_savepoint(THD *thd, L
 
   thd->transaction.savepoints= sv->prev;
 
-  DBUG_RETURN(test(res));
+  DBUG_RETURN(my_test(res));
 }
 
 
@@ -853,7 +853,7 @@ bool trans_xa_commit(THD *thd)
   else if (xa_state == XA_IDLE && thd->lex->xa_opt == XA_ONE_PHASE)
   {
     int r= ha_commit_trans(thd, TRUE);
-    if ((res= test(r)))
+    if ((res= my_test(r)))
       my_error(r == 1 ? ER_XA_RBROLLBACK : ER_XAER_RMERR, MYF(0));
   }
   else if (xa_state == XA_PREPARED && thd->lex->xa_opt == XA_NONE)
@@ -881,9 +881,9 @@ bool trans_xa_commit(THD *thd)
       DEBUG_SYNC(thd, "trans_xa_commit_after_acquire_commit_lock");
 
       if (tc_log)
-        res= test(tc_log->commit(thd, /* all */ true));
+        res= my_test(tc_log->commit(thd, /* all */ true));
       else
-        res= test(ha_commit_low(thd, /* all */ true));
+        res= my_test(ha_commit_low(thd, /* all */ true));
 
       if (res)
         my_error(ER_XAER_RMERR, MYF(0));
