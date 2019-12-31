$NetBSD: patch-biboutput.ml,v 1.2 2019/12/31 19:46:12 markd Exp $

fixed compilation with recent versions of OCaml 
git commit 8f25afb95a839c9f9522a34013d5c905af14378b 

--- biboutput.ml.orig	2014-07-04 07:51:21.000000000 +0000
+++ biboutput.ml
@@ -32,7 +32,7 @@ let is_url s = Str.string_match url_re s
 
 let print_atom html ch = function
   | Id s ->
-      if html & not (abbrev_is_implicit s) then
+      if html && not (abbrev_is_implicit s) then
 	begin
 	  Html.open_href ch ("#" ^ s);
 	  output_string ch s;
@@ -40,7 +40,7 @@ let print_atom html ch = function
 	end
       else
 	output_string ch s
-  | String s when html & is_url s ->
+  | String s when html && is_url s ->
       output_string ch "{";
       Html.open_href ch s;
       output_string ch s;
@@ -131,9 +131,9 @@ let print_command remove rename html htm
                      with Not_found -> field
                    in
 	           output_string ch (",\n  " ^ ofield ^ " = ");
-	           if html & field = "crossref" then
+	           if html && field = "crossref" then
 		     print_crossref html ch l
-	           else if html & is_link_field field then
+	           else if html && is_link_field field then
 		     print_link_field ch l
 	           else
 		     print_atom_list html ch l
@@ -154,26 +154,16 @@ exception Bad_input_for_php of string
 
 (* inspired from String.escaped *)
 let add_backslashes s =
-  let n = ref 0 in
-  for i = 0 to String.length s - 1 do
-    n := !n +
-      (match String.unsafe_get s i with
-         | '\'' | '\\' -> 2
-         | _ -> 1)
+  let n = String.length s in
+  let b = Buffer.create (2 * n) in
+  for i = 0 to n - 1 do
+    let c = String.unsafe_get s i in
+    begin match c with
+    | '\'' | '\\' -> Buffer.add_char b '\\'
+    | _ -> () end;
+    Buffer.add_char b c
   done;
-  if !n = String.length s then s else begin
-    let s' = String.create !n in
-    n := 0;
-    for i = 0 to String.length s - 1 do
-      let c = String.unsafe_get s i in
-      begin match c with
-        | ('\'' | '\\') -> String.unsafe_set s' !n '\\'; incr n
-        | _ -> ()
-      end;
-      String.unsafe_set s' !n c; incr n
-    done;
-    s'
-  end
+  Buffer.contents b
 
 let php_print_atom ch = function
   | Id s -> fprintf ch "\'%s\'" s
