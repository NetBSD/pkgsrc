$NetBSD: patch-common_hbase_memo.ml,v 1.1 2021/08/15 06:38:38 dholland Exp $

Fix build with current ocaml.

--- common/hbase/memo.ml~	2007-12-10 17:19:28.000000000 +0000
+++ common/hbase/memo.ml
@@ -92,7 +92,7 @@ let resize hashfun tbl =
   let osize = Array.length odata in
   let nsize = min (2 * osize + 1) Sys.max_array_length in
   if nsize <> osize then begin
-    let ndata = Array.create nsize Empty in
+    let ndata = Array.make nsize Empty in
     let rec insert_bucket = function
         Empty -> ()
       | Cons(key, data, rest) ->
@@ -530,7 +530,7 @@ module MakeLater(M:MemoType) = struct
       None -> None 
     | Some t -> (try Some (H.find t a) with Not_found -> None)
 
-  let memoize f =
+  let memoize (f: M.arg -> M.res) =
     if (Prefs.read memo_off || Safelist.mem M.name (Prefs.read memo_skip)) then f 
     else gen_memoize M.name M.format_arg M.format_res 
       H.find H.add get_table None f
@@ -561,7 +561,7 @@ module MakeLater2(M:MemoType2) = struct
       None -> None 
     | Some t -> (try Some (H.find t a) with Not_found -> None)
 	      
-  let memoize f = 
+  let memoize (f: M.arg -> M.res) = 
       if (Prefs.read memo_off || Safelist.mem M.name (Prefs.read memo_skip)) then f 
       else 
 	gen_memoize M.name M.format_arg M.format_res 
