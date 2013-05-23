$NetBSD: patch-net__scope.cc,v 1.1 2013/05/23 15:00:00 joerg Exp $

--- net_scope.cc.orig	2013-05-22 14:46:10.000000000 +0000
+++ net_scope.cc
@@ -221,11 +221,7 @@ map<perm_string,NetScope::param_expr_t>:
       if (idx != parameters.end())
 	    return idx;
 
-      idx = localparams.find(perm_string::literal(key));
-      if (idx != localparams.end())
-	    return idx;
-
-      return (map<perm_string,param_expr_t>::iterator) 0;
+      return localparams.find(perm_string::literal(key));
 }
 
 NetScope::TYPE NetScope::type() const
