$NetBSD: patch-bibfilter.ml,v 1.1 2019/12/31 19:46:12 markd Exp $

fixed compilation with recent versions of OCaml 
git commit 8f25afb95a839c9f9522a34013d5c905af14378b 

--- bibfilter.ml.orig	2014-07-04 07:51:21.000000000 +0000
+++ bibfilter.ml
@@ -28,7 +28,7 @@ let filter biblio criterion =
   Bibtex.fold
     (fun entry keys ->
        match entry with
-	   Entry(entry_type,key,fields) 
+	   Entry(entry_type,key,fields)
 	     when criterion entry_type key fields ->
 	       KeySet.add key keys
 	 | _ -> keys)
@@ -41,9 +41,9 @@ let filter biblio criterion =
 
 let rec needed_keys_for_field biblio field value keys abbrevs =
   if field = "crossref"
-  then 
+  then
     match value with
-	[String(s)] -> 
+	[String(s)] ->
 	  if not (KeySet.mem s keys) then
 	    begin
 	      try
@@ -60,7 +60,7 @@ let rec needed_keys_for_field biblio fie
 		(keys,abbrevs)
 	    end
 	  else (keys,abbrevs)
-      | _ -> 
+      | _ ->
 	  if not !Options.quiet then
 	    eprintf "Warning: cross-references must be constant strings\n";
 	  if !Options.warn_error then exit 2;
@@ -69,9 +69,9 @@ let rec needed_keys_for_field biblio fie
     List.fold_right
       (fun a (keys,abbrevs) ->
 	 match a with
-	     Id(id) -> 
-	       let id = String.lowercase id in		 
-	       if not (KeySet.mem id abbrevs) 
+	     Id(id) ->
+	       let id = String.lowercase_ascii id in
+	       if not (KeySet.mem id abbrevs)
 	       then
 		 try
 		   let e = find_abbrev id biblio in
@@ -81,7 +81,7 @@ let rec needed_keys_for_field biblio fie
 		   needed_keys_for_entry biblio keys (KeySet.add id abbrevs) e
 		 with Not_found ->
 		   if abbrev_is_implicit id then (keys,abbrevs)
-		   else 
+		   else
 		     begin
 		       if not !Options.quiet then
 			 eprintf "Warning: string \"%s\" not found.\n" id;
@@ -101,7 +101,7 @@ and needed_keys_for_entry biblio keys ab
 	   needed_keys_for_field biblio field value keys abbrevs)
 	fields
 	(keys,abbrevs)
-  | Abbrev(field,value) -> 
+  | Abbrev(field,value) ->
       needed_keys_for_field biblio field value keys abbrevs
   | _ -> (keys,abbrevs)
 
