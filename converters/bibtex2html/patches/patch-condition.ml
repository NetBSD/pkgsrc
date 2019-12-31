$NetBSD: patch-condition.ml,v 1.2 2019/12/31 19:46:12 markd Exp $

fixed compilation with recent versions of OCaml 
git commit 8f25afb95a839c9f9522a34013d5c905af14378b 

--- condition.ml.orig	2014-07-04 07:51:21.000000000 +0000
+++ condition.ml
@@ -22,10 +22,10 @@ type constante =
   | Field of string
   | Cte of string
 ;;
-   
+
 type condition =
-  | True 
-  | False 
+  | True
+  | False
   | And of condition * condition
   | Or of condition * condition
   | Not of condition
@@ -52,12 +52,12 @@ let evaluate_constante entrytype key fie
   | Cte(x) -> Latex_accents.normalize false x
 ;;
 
-let eval_comp v1 op v2 = 
+let eval_comp v1 op v2 =
   match op with
-    | "=" -> String.lowercase v1 = String.lowercase v2
-    | "<>" -> String.lowercase v1 <> String.lowercase v2	    
+    | "=" -> String.lowercase_ascii v1 = String.lowercase_ascii v2
+    | "<>" -> String.lowercase_ascii v1 <> String.lowercase_ascii v2
     | "==" -> v1 = v2
-    | "!=" -> v1 <> v2	    
+    | "!=" -> v1 <> v2
     | _ ->
 	let n1 = int_of_string v1
 	and n2 = int_of_string v2 in
@@ -84,12 +84,12 @@ let rec evaluate_rec entrytype key field
   | Comp(c1,op,c2) ->
       begin
 	try
-	  let v1 = evaluate_constante entrytype key fields c1 
+	  let v1 = evaluate_constante entrytype key fields c1
 	  and v2 = evaluate_constante entrytype key fields c2 in
 	    try
 	      eval_comp v1 op v2
 	    with
-		Failure "int_of_string" -> 
+		Failure _ ->
 		  if not !Options.quiet then begin
 		    eprintf "Warning: cannot compare non-numeric values ";
 		    eprintf "%s and %s in entry %s\n" v1 v2 key
@@ -126,7 +126,7 @@ let evaluate_cond entrytype key fields c
   with
       Not_found -> assert false
 ;;
-    
+
 let string_of_constante = function
     Key -> "(key)"
   | Entrytype -> "(entrytype)"
@@ -140,9 +140,8 @@ let rec print = function
   | And(c1,c2) -> printf "("; print c1; printf " and "; print c2; printf ")"
   | Or(c1,c2) -> printf "("; print c1; printf " or "; print c2; printf ")"
   | Not(c) -> printf "(not "; print c; printf ")"
-  | Comp(c1,op,c2) -> 
+  | Comp(c1,op,c2) ->
       printf "%s %s %s" (string_of_constante c1) op (string_of_constante c2)
   | Match(c,s) -> printf "%s : (regexp)" (string_of_constante c)
   | Exists(f) -> printf "exists %s" f
 ;;
-
