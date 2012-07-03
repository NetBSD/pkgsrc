$NetBSD: patch-libxorp_transaction.hh,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- libxorp/transaction.hh.orig	2009-01-05 18:30:58.000000000 +0000
+++ libxorp/transaction.hh
@@ -276,7 +276,7 @@ private:
     uint32_t _max_pending;
     uint32_t _next_tid;
     
-    friend class Transaction; // for Transaction to call operation_result()
+    friend struct Transaction; // for Transaction to call operation_result()
 };
 
 #endif // __LIBXORP_TRANSACTION_HH__
