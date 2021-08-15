$NetBSD: patch-common_hbase_misc.ml,v 1.1 2021/08/15 06:38:38 dholland Exp $

Fix build with current ocaml.

--- common/hbase/misc.ml~	2009-08-17 20:39:00.000000000 +0000
+++ common/hbase/misc.ml
@@ -207,20 +207,20 @@ let escape (escapeChar: char -> string) 
   let result = 
     if !n = String.length s then s else 
     begin
-      let s' = String.create !n in   
+      let s' = Bytes.create !n in   
       n := 0;
       for i = 0 to String.length s - 1 do 
         let c = String.get s i in
         let cEscaped = escapeChar c in
         if String.length cEscaped = 1 then begin
-          String.set s' !n c; incr n
+          Bytes.set s' !n c; incr n
         end else
           for i = 0 to String.length cEscaped - 1 do begin
-            String.set s' !n (String.get cEscaped i);
+            Bytes.set s' !n (String.get cEscaped i);
             incr n;
           end done
       done;
-      s'
+      Bytes.to_string s'
     end
   in
   debug(fun () -> Util.format "escape returns %s@\n" result);
@@ -231,10 +231,10 @@ let generic_escape_char escapedchars c =
   if c = '\\' then 
     "\\\\"
   else if String.contains escapedchars c then
-    let str = String.create 2 in
-    String.set str 0 '\\';
-    String.set str 1 c;
-    str
+    let str = Bytes.create 2 in
+    Bytes.set str 0 '\\';
+    Bytes.set str 1 c;
+    Bytes.to_string str
   else
     "-"
 
@@ -251,20 +251,20 @@ let generic_unescape s =
       else
         loop (i + 1) (n + 1)
     in
-    let s' = String.create (loop 0 0) in
+    let s' = Bytes.create (loop 0 0) in
     let rec loop i i' = 
       if i >= String.length s then
         ()
       else if s.[i] = '\\' then begin
-        s'.[i'] <- s.[i+1]; (* assumes that '\' always followed by a char *)
+        Bytes.set s' i' (String.get s (i+1)); (* assumes that '\' always followed by a char *)
         loop (i + 2) (i' + 1)
       end else begin
-        s'.[i'] <- s.[i];
+        Bytes.set s' i' (String.get s i);
         loop (i + 1) (i' + 1)
       end
     in
     loop 0 0;
-    s'
+    Bytes.to_string s'
 
 (* find c, skipping all the escaped characters, e.g., "\;" *)
 let rec index_rec_nonescape s i c = 
@@ -511,9 +511,9 @@ let rec remove_file_or_dir d =
 
 let read_chan chan =
   let nbytes = in_channel_length chan in
-  let string = String.create nbytes in
+  let string = Bytes.create nbytes in
   really_input chan string 0 nbytes;
-  string
+  Bytes.to_string string
 
 let read file =
   if file = "-" then
@@ -584,7 +584,7 @@ let rec cp_dash_r fromhere tohere =
 (* ### Should trap unix errors and do something sensible... *)
 let backup path =
   let newpath = backup_file_name path in
-  if is_dir path or Sys.file_exists path then cp_dash_r path newpath
+  if is_dir path || Sys.file_exists path then cp_dash_r path newpath
 
 (* exec : string -> string *)
 let exec s = 
