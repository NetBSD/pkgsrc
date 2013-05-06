$NetBSD: patch-sql_sys__vars.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sys_vars.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sys_vars.cc
@@ -2055,7 +2055,7 @@ static bool fix_optimizer_switch(sys_var
 {
   SV *sv= (type == OPT_GLOBAL) ? &global_system_variables : &thd->variables;
   sv->engine_condition_pushdown= 
-    test(sv->optimizer_switch & OPTIMIZER_SWITCH_ENGINE_CONDITION_PUSHDOWN);
+    my_test(sv->optimizer_switch & OPTIMIZER_SWITCH_ENGINE_CONDITION_PUSHDOWN);
 
   return false;
 }
