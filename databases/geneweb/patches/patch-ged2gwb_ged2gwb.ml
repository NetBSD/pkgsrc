$NetBSD: patch-ged2gwb_ged2gwb.ml,v 1.1 2012/12/16 22:39:47 dholland Exp $

Replace long-deprecated Stdpp.Exc_located with Ploc.Exc.

--- ged2gwb/ged2gwb.ml~	2007-09-12 09:58:44.000000000 +0000
+++ ged2gwb/ged2gwb.ml
@@ -857,10 +857,10 @@ value date_of_field pos d =
     let s = Stream.of_string (String.uppercase d) in
     date_str.val := d;
     try Some (Grammar.Entry.parse date_value s) with
-    [ Stdpp.Exc_located loc (Stream.Error _) ->
+    [ Ploc.Exc loc (Stream.Error _) ->
         let s = Stream.of_string (String.uppercase d) in
         try Some (Grammar.Entry.parse date_value_recover s) with
-        [ Stdpp.Exc_located loc (Stream.Error _) -> Some (Dtext d) ] ]
+        [ Ploc.Exc loc (Stream.Error _) -> Some (Dtext d) ] ]
   }
 ;
 
@@ -1327,7 +1327,7 @@ value decode_date_interval pos s =
     | Begin d -> (Some d, None)
     | End d -> (None, Some d) ]
   with
-  [ Stdpp.Exc_located _ _ | Not_found ->
+  [ Ploc.Exc _ _ | Not_found ->
       do { print_bad_date pos s; (None, None) } ]
 ;
 
@@ -2968,7 +2968,7 @@ The database \"%s\" already exists. Use 
 try main () with e ->
   let e =
     match e with
-    [ Stdpp.Exc_located _ e -> e
+    [ Ploc.Exc _ e -> e
     |  _ -> e ]
   in
   do {
