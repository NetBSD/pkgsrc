$NetBSD: patch-src_mstring.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/mstring.ml.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/mstring.ml
@@ -91,12 +91,12 @@ let dec_to_hex i =
 (* Converting a hex stored string *)
 let hex_to_string s =
   let len = String.length s / 2 in
-  let res = String.create len in
+  let res = Bytes.create len in
     for i = 0 to len - 1 do
-      res.[i] <-
-        char_of_int ( 16 * (hex_to_dec s.[i + i]) + hex_to_dec s.[i + i + 1])
+      Bytes.set res i
+        (char_of_int ( 16 * (hex_to_dec s.[i + i]) + hex_to_dec s.[i + i + 1]))
       done;
-    res;;
+    Bytes.to_string res;;
 
 let gensym =
   let cnter = ref 0 in
@@ -125,37 +125,37 @@ let catenate_sep = String.concat;;
 let norm_crlf lastwascr buf offs len =
   let rpos = ref offs
   and wpos = ref 0
-  and dest = String.create (len + 1) (* we need one more char *)
+  and dest = Bytes.create (len + 1) (* we need one more char *)
   and limit = offs + len - 1
   and lastiscr = ref false in
   if lastwascr then
     if buf.[!rpos] = '\n' then begin
-      dest.[!wpos] <- '\n';
+      Bytes.set dest !wpos '\n';
       incr rpos; incr wpos
     end else begin
-      dest.[!wpos] <- '\n'; incr wpos
+      Bytes.set dest !wpos '\n'; incr wpos
     end;
 
   while !rpos < limit do
     match buf.[!rpos] with
-    | '\n' -> dest.[!wpos] <- '\n'; incr rpos; incr wpos
+    | '\n' -> Bytes.set dest !wpos '\n'; incr rpos; incr wpos
     | '\r' ->
       if buf.[!rpos + 1] = '\n' then begin
-        dest.[!wpos] <- '\n'; rpos := !rpos + 2; incr wpos
+        Bytes.set dest !wpos '\n'; rpos := !rpos + 2; incr wpos
       end else begin
-        dest.[!wpos] <- '\n'; incr rpos; incr wpos end
-    | c -> dest.[!wpos] <- c; incr rpos; incr wpos
+        Bytes.set dest !wpos '\n'; incr rpos; incr wpos end
+    | c -> Bytes.set dest !wpos c; incr rpos; incr wpos
   done;
   begin match buf.[offs+len-1] with
-  | '\n' -> dest.[!wpos] <- '\n'; incr wpos
+  | '\n' -> Bytes.set dest !wpos '\n'; incr wpos
   | '\r' -> lastiscr := true
-  | c -> dest.[!wpos] <- c; incr wpos
+  | c -> Bytes.set dest !wpos c; incr wpos
   end;
-  String.sub dest 0 !wpos, !lastiscr;;
+  (Bytes.sub_string dest 0 !wpos, !lastiscr);;
 
 let hexchar c =
-  let s = String.make 3 '%'
+  let s = Bytes.make 3 '%'
   and i = int_of_char c in
-  s.[1] <- dec_to_hex (i / 16);
-  s.[2] <- dec_to_hex (i mod 16);
-  s;;
+  Bytes.set s 1 (dec_to_hex (i / 16));
+  Bytes.set s 2 (dec_to_hex (i mod 16));
+  Bytes.to_string s;;
