$NetBSD: patch-sql_sql__prepare.h,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_prepare.h.orig	2013-05-05 20:54:42.000000000 +0000
+++ sql/sql_prepare.h
@@ -289,7 +289,7 @@ public:
     one.
     Never fails.
   */
-  bool has_next_result() const { return test(m_current_rset->m_next_rset); }
+  bool has_next_result() const { return my_test(m_current_rset->m_next_rset); }
   /**
     Only valid to call if has_next_result() returned true.
     Otherwise the result is undefined.
@@ -297,7 +297,7 @@ public:
   bool move_to_next_result()
   {
     m_current_rset= m_current_rset->m_next_rset;
-    return test(m_current_rset);
+    return my_test(m_current_rset);
   }
 
   ~Ed_connection() { free_old_result(); }
