$NetBSD: patch-src_misc.ml,v 1.1 2018/03/14 06:27:21 dholland Exp $

Fix build with ocaml 4.06.

--- src/misc.ml~	2006-04-20 15:17:30.000000000 +0000
+++ src/misc.ml
@@ -158,20 +158,20 @@ let escape (escapeChar: char -> string) 
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
-	  String.set s' !n c; incr n
+	  Bytes.set s' !n c; incr n
 	end else
 	  for i = 0 to String.length cEscaped - 1 do begin
-	    String.set s' !n (String.get cEscaped i);
+	    Bytes.set s' !n (String.get cEscaped i);
 	    incr n;
 	  end done
       done;
-      s'
+      Bytes.to_string s'
     end
   in
   debug(fun () -> Format.printf "escape returns %s\n" result);
@@ -182,10 +182,10 @@ let generic_escape_char escapedchars c =
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
 
@@ -202,20 +202,20 @@ let generic_unescape s =
       else
 	loop (i + 1) (n + 1)
     in
-    let s' = String.create (loop 0 0) in
+    let s' = Bytes.create (loop 0 0) in
     let rec loop i i' = 
       if i >= String.length s then
 	()
       else if s.[i] = '\\' then begin
-	s'.[i'] <- s.[i+1]; (* assumes that '\' always followed by a char *)
+	Bytes.set s' i' s.[i+1]; (* assumes that '\' always followed by a char *)
 	loop (i + 2) (i' + 1)
       end else begin
-	s'.[i'] <- s.[i];
+	Bytes.set s' i' s.[i];
 	loop (i + 1) (i' + 1)
       end
     in
     loop 0 0;
-    s'
+    Bytes.to_string s'
       
 (* find c, skipping all the escaped characters, e.g., "\;" *)
 let rec index_rec_nonescape s i c = 
@@ -455,9 +455,9 @@ let rec remove_file_or_dir d =
       
 let read_chan chan =
   let nbytes = in_channel_length chan in
-  let string = String.create nbytes in
+  let string = Bytes.create nbytes in
   really_input chan string 0 nbytes;
-  string
+  Bytes.to_string string
       
 let read file =
   if file = "-" then
