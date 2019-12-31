$NetBSD: patch-bibtex.ml,v 1.1 2019/12/31 19:46:12 markd Exp $

fixed compilation with recent versions of OCaml 
git commit 8f25afb95a839c9f9522a34013d5c905af14378b 

--- bibtex.ml.orig	2014-07-04 07:51:21.000000000 +0000
+++ bibtex.ml
@@ -17,16 +17,16 @@
 (*s Datatype for BibTeX bibliographies. *)
 
 type entry_type = string
-		    
+
 type key = string
 
 module KeySet = Set.Make(struct type t = key let compare = compare end)
-	     
+
 type atom =
   | Id of string
   | String of string
 
-type command = 
+type command =
   | Comment of string
   | Preamble of atom list
   | Abbrev of string * atom list
@@ -51,9 +51,9 @@ let find_entry key biblio =
     match b with
       | [] -> raise Not_found
       | (Entry (_,s,_) as e) :: b ->
-	  if String.lowercase s = key then e else find key b
+	  if String.lowercase_ascii s = key then e else find key b
       | _ :: b -> find key b
-  in find (String.lowercase key) biblio
+  in find (String.lowercase_ascii key) biblio
 
 let add_new_entry command biblio = command :: biblio
 
@@ -75,7 +75,7 @@ let add_entry command biblio =
 	  try
 	    let new_bib = remove_entry key biblio in
 	    command :: new_bib
-	  with Not_found -> 
+	  with Not_found ->
 	    command :: biblio
 	end
     | _ -> command::biblio
@@ -96,16 +96,16 @@ let merge_biblios b1 b2 =
       b1
       KeySet.empty
   in
-  let new_b1 = 
+  let new_b1 =
     fold
       (fun entry accu -> match entry with
-	 | Entry (_,key,_) -> 
-	     if KeySet.mem key b2keys then 
+	 | Entry (_,key,_) ->
+	     if KeySet.mem key b2keys then
 	       begin
 		 Format.eprintf "Warning, key '%s' duplicated@." key;
 		 if !Options.warn_error then exit 2;
-		 accu 
-	       end 
+		 accu
+	       end
 	     else entry :: accu
 	 | _ -> entry :: accu)
       b1
@@ -114,13 +114,13 @@ let merge_biblios b1 b2 =
   let new_bib =
     fold
       (fun entry accu -> match entry with
-	 | Abbrev (key,_) -> 
-	     if KeySet.mem key b1abbrevs then 
+	 | Abbrev (key,_) ->
+	     if KeySet.mem key b1abbrevs then
 	       begin
 		 Format.eprintf "Warning, key '%s' duplicated@." key;
 		 if !Options.warn_error then exit 2;
-		 accu 
-	       end 
+		 accu
+	       end
 	     else entry :: accu
 	 | _ -> entry :: accu)
       b2
@@ -137,7 +137,7 @@ let month_env =
 let abbrev_is_implicit key =
   try
     let _ = int_of_string key in true
-  with Failure "int_of_string" ->
+  with Failure _ ->
     try
       let _ = List.assoc key month_env in true
     with Not_found -> false
@@ -153,12 +153,12 @@ i*)
 let rec find_abbrev key biblio =
   match biblio with
     | [] -> raise Not_found
-    | (Abbrev (s,_) as e) :: b -> 
+    | (Abbrev (s,_) as e) :: b ->
 	if s = key then e
 	else find_abbrev key b
     | _ :: b -> find_abbrev key b
 
-let concat_atom_lists a1 a2 = 
+let concat_atom_lists a1 a2 =
   match (a1,a2) with
     | ([String s1], [String s2]) -> [String (s1 ^ s2)]
     | _ -> a1 @ a2
@@ -175,10 +175,10 @@ let rec expand_list = function
   | [] -> []
   | ((Id s) as a) :: rem ->
       begin
-	try 
+	try
 	  let v = find_abbrev_in_table s in
 	  concat_atom_lists v (expand_list rem)
-	with Not_found -> 
+	with Not_found ->
 	  concat_atom_lists [a] (expand_list rem)
       end
   | ((String _) as a) :: rem ->
@@ -188,13 +188,13 @@ let rec expand_fields = function
   | [] ->  []
   | (n,l) :: rem -> (n, expand_list l) :: (expand_fields rem)
 
-let rec expand_abbrevs biblio = 
-  fold 
+let rec expand_abbrevs biblio =
+  fold
     (fun command accu ->
        match command with
 	 | Abbrev (a,l) ->
 	     let s = expand_list l in
-	     add_abbrev a s; 
+	     add_abbrev a s;
 	     accu
 	 | Entry (t,k,f) ->
 	     Entry (t,k,expand_fields f) :: accu
@@ -205,30 +205,31 @@ let rec expand_abbrevs biblio =
 
 let add_crossref_fields =
   List.fold_left
-    (fun acc ((x,_) as d) -> 
+    (fun acc ((x,_) as d) ->
        if List.mem_assoc x acc then acc else d::acc)
 
 
-let rec expand_crossrefs biblio = 
+let rec expand_crossrefs biblio =
   let crossref_table = Hashtbl.create 97 in
-  let add_crossref a l = Hashtbl.add crossref_table (String.lowercase a) l in
-  let find_crossref a = Hashtbl.find crossref_table (String.lowercase a) in
-  let replace_crossref a l = 
-    Hashtbl.replace crossref_table (String.lowercase a) l 
-  in
+  let add_crossref a l =
+    Hashtbl.add crossref_table (String.lowercase_ascii a) l in
+  let find_crossref a =
+    Hashtbl.find crossref_table (String.lowercase_ascii a) in
+  let replace_crossref a l =
+    Hashtbl.replace crossref_table (String.lowercase_ascii a) l in
   (* first phase: record needed crossrefs in table *)
-  List.iter 
+  List.iter
     (fun command ->
        match command with
 	 | Entry (t,k,f) ->
 	     begin
 	       try
 		 match List.assoc "crossref" f with
-		   | [String(s)] -> 
+		   | [String(s)] ->
 		       add_crossref s []
-		   | _ -> 
+		   | _ ->
 		       begin
-			 Format.eprintf 
+			 Format.eprintf
 			   "Warning: invalid cross-reference in entry '%s'.@." k;
 			 if !Options.warn_error then exit 2;
 		   end
@@ -237,12 +238,12 @@ let rec expand_crossrefs biblio =
 	 | _ -> ())
     biblio;
   (* second phase: record crossrefs data in table *)
-  List.iter 
+  List.iter
     (fun command ->
        match command with
 	 | Entry (t,k,f) ->
 	     begin
-	       try 
+	       try
 		 let _ = find_crossref k in
 		 if !Options.debug then
 		   Format.eprintf "recording cross-reference '%s'.@." k;
@@ -252,21 +253,21 @@ let rec expand_crossrefs biblio =
 	 | _ -> ())
     biblio;
   (* third phase: expand crossrefs *)
-  fold 
+  fold
     (fun command accu ->
        match command with
 	 | Entry (t,k,f) ->
 	     begin
 	       try
 		 match List.assoc "crossref" f with
-		   | [String(s)] -> 
+		   | [String(s)] ->
 		       begin
-			 try 
+			 try
 			   let f = List.remove_assoc "crossref" f in
 			   let f' = find_crossref s in
 			   if f' = [] then
 			     begin
-			       Format.eprintf 
+			       Format.eprintf
 				 "Warning: cross-reference '%s' not found.@." s;
 			       if !Options.warn_error then exit 2;
 			     end;
@@ -284,7 +285,7 @@ let rec expand_crossrefs biblio =
 
 
 
-let sort comp bib = 
+let sort comp bib =
   let comments,preambles,abbrevs,entries =
     List.fold_left
       (fun (c,p,a,e) command ->
@@ -307,4 +308,3 @@ let sort comp bib =
 
 
 let current_key = ref ""
-
