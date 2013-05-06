$NetBSD: patch-sql_sp__head.h,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sp_head.h.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sp_head.h
@@ -859,7 +859,7 @@ public:
     else if (m_flags & HAS_SQLCOM_FLUSH)
       my_error(ER_STMT_NOT_ALLOWED_IN_SF_OR_TRG, MYF(0), "FLUSH");
 
-    return test(m_flags &
+    return my_test(m_flags &
 		(CONTAINS_DYNAMIC_SQL|MULTI_RESULTS|HAS_SET_AUTOCOMMIT_STMT|
                  HAS_COMMIT_OR_ROLLBACK|HAS_SQLCOM_RESET|HAS_SQLCOM_FLUSH));
   }
