$NetBSD: patch-rib_redist__xrl.cc,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- rib/redist_xrl.cc.orig	2009-01-05 18:31:07.000000000 +0000
+++ rib/redist_xrl.cc
@@ -1032,11 +1032,11 @@ RedistTransactionXrlOutput<A>::add_route
     // current transaction and start a new one.
     //
     if (this->transaction_size() >= MAX_TRANSACTION_SIZE) {
-	enqueue_task(new CommitTransaction<A>(this));
-	enqueue_task(new StartTransaction<A>(this));
+	this->enqueue_task(new CommitTransaction<A>(this));
+	this->enqueue_task(new StartTransaction<A>(this));
     }
 
-    enqueue_task(new AddTransactionRoute<A>(this, ipr));
+    this->enqueue_task(new AddTransactionRoute<A>(this, ipr));
     if (no_running_tasks)
 	this->start_next_task();
 }
@@ -1054,18 +1054,18 @@ RedistTransactionXrlOutput<A>::delete_ro
     bool no_running_tasks = (this->_queued == 0);
 
     if (this->transaction_size() == 0)
-	enqueue_task(new StartTransaction<A>(this));
+	this->enqueue_task(new StartTransaction<A>(this));
 
     //
     // If the accumulated transaction size is too large, commit the
     // current transaction and start a new one.
     //
     if (this->transaction_size() >= MAX_TRANSACTION_SIZE) {
-	enqueue_task(new CommitTransaction<A>(this));
-	enqueue_task(new StartTransaction<A>(this));
+	this->enqueue_task(new CommitTransaction<A>(this));
+	this->enqueue_task(new StartTransaction<A>(this));
     }
 
-    enqueue_task(new DeleteTransactionRoute<A>(this, ipr));
+    this->enqueue_task(new DeleteTransactionRoute<A>(this, ipr));
     if (no_running_tasks)
 	this->start_next_task();
 }
@@ -1105,7 +1105,7 @@ RedistTransactionXrlOutput<A>::task_comp
 	// If transaction in progress, and this is the last add/delete,
 	// then send "commit transaction".
 	//
-	enqueue_task(new CommitTransaction<A>(this));
+	this->enqueue_task(new CommitTransaction<A>(this));
 	this->start_next_task();
 	return;
     }
