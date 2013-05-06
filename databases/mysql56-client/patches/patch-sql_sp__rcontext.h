$NetBSD: patch-sql_sp__rcontext.h,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sp_rcontext.h.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sp_rcontext.h
@@ -453,7 +453,7 @@ public:
   bool close(THD *thd);
 
   bool is_open() const
-  { return test(m_server_side_cursor); }
+  { return my_test(m_server_side_cursor); }
 
   bool fetch(THD *thd, List<sp_variable> *vars);
 
