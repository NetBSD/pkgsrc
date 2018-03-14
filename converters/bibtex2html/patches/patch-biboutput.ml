$NetBSD: patch-biboutput.ml,v 1.1 2018/03/14 08:28:44 dholland Exp $

Fix build with ocaml 4.06.
Silence deprecation warnings.

--- biboutput.ml~	2014-07-04 07:51:21.000000000 +0000
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
@@ -162,17 +162,17 @@ let add_backslashes s =
          | _ -> 1)
   done;
   if !n = String.length s then s else begin
-    let s' = String.create !n in
+    let s' = Bytes.create !n in
     n := 0;
     for i = 0 to String.length s - 1 do
       let c = String.unsafe_get s i in
       begin match c with
-        | ('\'' | '\\') -> String.unsafe_set s' !n '\\'; incr n
+        | ('\'' | '\\') -> Bytes.unsafe_set s' !n '\\'; incr n
         | _ -> ()
       end;
-      String.unsafe_set s' !n c; incr n
+      Bytes.unsafe_set s' !n c; incr n
     done;
-    s'
+    Bytes.to_string s'
   end
 
 let php_print_atom ch = function
