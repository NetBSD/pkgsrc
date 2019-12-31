$NetBSD: patch-translate.ml,v 1.1 2019/12/31 19:46:12 markd Exp $

fixed compilation with recent versions of OCaml 
git commit 8f25afb95a839c9f9522a34013d5c905af14378b 

--- translate.ml.orig	2014-07-04 07:51:22.000000000 +0000
+++ translate.ml
@@ -69,23 +69,23 @@ let default_fields =
 let (fields : field_info list ref) = ref default_fields
 
 let add_field s =
-  let u = String.lowercase s in
+  let u = String.lowercase_ascii s in
   Biboutput.add_link_field u;
   fields := (u, None) :: (List.remove_assoc u !fields)
 
 let add_named_field s name =
-  let u = String.lowercase s in
+  let u = String.lowercase_ascii s in
   Biboutput.add_link_field u;
   if u = "abstract" then abstract_name := name;
   if not !both || u <> "abstract" then
     fields := (u, Some name) :: (List.remove_assoc u !fields)
 
 let add_note_field s =
-  let u = String.lowercase s in
+  let u = String.lowercase_ascii s in
   note_fields := !note_fields @ [u, NKlatex]
 
 let add_note_html_field s =
-  let u = String.lowercase s in
+  let u = String.lowercase_ascii s in
   note_fields := !note_fields @ [u, NKhtml]
 
 (* first pass to get the crossrefs *)
@@ -186,13 +186,13 @@ let file_suffixes =
 	 ".rtf"; ".RTF"; ".txt"; ".TXT"; ".html"; ".HTML" ])
 
 let is_http s =
-  String.length s > 3 & String.lowercase (String.sub s 0 4) = "http"
+  String.length s > 3 && String.lowercase_ascii (String.sub s 0 4) = "http"
 
 let is_ftp s =
-  String.length s > 2 & String.lowercase (String.sub s 0 3) = "ftp"
+  String.length s > 2 && String.lowercase_ascii (String.sub s 0 3) = "ftp"
 
 let is_www s =
-  String.length s > 3 & String.lowercase (String.sub s 0 4) = "www:"
+  String.length s > 3 && String.lowercase_ascii (String.sub s 0 4) = "www:"
 
 let is_url s = is_http s || is_ftp s || is_www s
 
@@ -203,7 +203,8 @@ let file_type f =
     if is_http f then "http" else if is_ftp f then "ftp" else "www:"
 
 let get_url s =
-  if (String.length s > 3 & String.lowercase (String.sub s 0 3) = "www") then
+  if String.length s > 3 && String.lowercase_ascii (String.sub s 0 3) = "www"
+  then
     String.sub s 4 (String.length s - 4)
   else
     s
@@ -215,7 +216,7 @@ let link_name (u, name) url s = match na
       if !raw_url then
 	url
       else if !use_label_name then
-	String.capitalize (String.lowercase u)
+	String.capitalize_ascii (String.lowercase_ascii u)
       else
 	s
 
@@ -422,16 +423,16 @@ let one_entry_summary ch biblio (_,b,((_
   output_string ch "\n\n";
   open_row ch;
   (* JK changes *)
-  if (not !nokeys) or !multiple then output_string ch "[";
+  if (not !nokeys) || !multiple then output_string ch "[";
   Html.open_anchor ch k;
-  if (not !nokeys) or !multiple then begin
+  if (not !nokeys) || !multiple then begin
     if !multiple then Html.open_href ch (k ^ !link_suffix);
     latex2html ch (if !use_keys then k else Hashtbl.find cite_tab k);
     if !multiple then Html.close_href ch;
   end else
     if !table <> NoTable then output_string ch "&nbsp;";
   Html.close_anchor ch;
-  if (not !nokeys) or !multiple then output_string ch "]";
+  if (not !nokeys) || !multiple then output_string ch "]";
   (* end of JK changes *)
   output_string ch "\n";
   new_column ch;
