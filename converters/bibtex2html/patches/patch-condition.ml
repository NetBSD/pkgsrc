$NetBSD: patch-condition.ml,v 1.1 2018/03/14 08:28:44 dholland Exp $

Silence deprecation warnings.

--- condition.ml~	2014-07-04 07:51:21.000000000 +0000
+++ condition.ml
@@ -54,8 +54,8 @@ let evaluate_constante entrytype key fie
 
 let eval_comp v1 op v2 = 
   match op with
-    | "=" -> String.lowercase v1 = String.lowercase v2
-    | "<>" -> String.lowercase v1 <> String.lowercase v2	    
+    | "=" -> String.lowercase_ascii v1 = String.lowercase_ascii v2
+    | "<>" -> String.lowercase_ascii v1 <> String.lowercase_ascii v2	    
     | "==" -> v1 = v2
     | "!=" -> v1 <> v2	    
     | _ ->
