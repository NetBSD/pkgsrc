$NetBSD: patch-src_xpm.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/xpm.ml.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/xpm.ml
@@ -27,31 +27,36 @@ let load file _opts =
   (* if the colors <= 256 then we create index8,
      otherwise create index16 *)
   if Array.length cmap <= 256 then begin
-    let buf = String.create (w * h) in
+    let buf = Bytes.create (w * h) in
     for i = 0 to w * h - 1 do
-      buf.[i] <- char_of_int imap.(i)
+      Bytes.set buf i (char_of_int imap.(i))
     done;
+    (* safe: we just created it AND create_with copies it *)
+    let buf' = Bytes.unsafe_to_string buf in
     Index8 (Index8.create_with w h []
-              { map = cmap; max = 256 - 1; } transparent buf)
+              { map = cmap; max = 256 - 1; } transparent buf')
   end else begin
-    let buf = String.create (w * h * 2) in
+    let buf = Bytes.create (w * h * 2) in
     for i = 0 to w * h - 1 do
-      buf.[i * 2    ] <- char_of_int (imap.(i) / 256);
-      buf.[i * 2 + 1] <- char_of_int (imap.(i) mod 256)
+      Bytes.set buf (i * 2    ) (char_of_int (imap.(i) / 256));
+      Bytes.set buf (i * 2 + 1) (char_of_int (imap.(i) mod 256))
     done;
+    (* safe: we just created it AND create_with copies it *)
+    let buf' = Bytes.unsafe_to_string buf in
     Index16 (Index16.create_with w h []
                { map = cmap; max = 256 * 256 - 1; }
-               transparent buf)
+               transparent buf')
   end;;
 
 let check_header filename =
   let len = 9 in
   let ic = open_in_bin filename in
   try
-    let str = String.create len in
+    let str = Bytes.create len in
     really_input ic str 0 len;
     close_in ic;
-    if str = "/* XPM */" then
+    (* safe: transient and private *)
+    if Bytes.unsafe_to_string str = "/* XPM */" then
       { header_width = -1;
     	header_height = -1;
     	header_infos = []; }
