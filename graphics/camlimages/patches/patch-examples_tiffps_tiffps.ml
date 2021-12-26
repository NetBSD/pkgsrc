$NetBSD: patch-examples_tiffps_tiffps.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

Silence nuisance warning about lowercase.

--- examples/tiffps/tiffps.ml~	2011-06-22 18:04:32.000000000 +0000
+++ examples/tiffps/tiffps.ml
@@ -51,7 +51,7 @@ let parse_length s = (* return in pt *)
     let digit, unit =
       if l > 2 then String.sub s 0 2, String.sub s (l-2) 2 else "", "" in
     try
-      List.assoc (String.lowercase unit) units *. float_of_string digit
+      List.assoc (String.lowercase_ascii unit) units *. float_of_string digit
     with
     | Not_found -> (* think it is in "pt" *) float_of_string s in
   prerr_endline (Printf.sprintf "%s -> %fpt" s v);
@@ -59,7 +59,7 @@ let parse_length s = (* return in pt *)
 
 (* Scanlined loader *)
 type scanlined_loader = {
-    read_next_line: (string -> unit);
+    read_next_line: (Bytes.t -> unit);
     close: (unit -> unit)
   };;
 
@@ -396,7 +396,7 @@ let main () =
       p "{ currentfile scanline readhexstring pop } false 3";
       p "colorimage";
 
-      let buf = String.create (imgw * 3) in
+      let buf = Bytes.create (imgw * 3) in
       for y = 0 to y1 - 1 do th.read_next_line buf done;
       let prevperdec = ref (-1) in
       for y = y1 to y1 + h - 1 do
@@ -411,7 +411,7 @@ let main () =
             function x ->
               let adrs = x * 3 in
               for i = 0 to 2 do
-                print_string (sprintf "%02x" (Char.code buf.[adrs+i]))
+                print_string (sprintf "%02x" (Char.code (Bytes.get buf (adrs+i))))
               done
           else
             let mono r g b =
@@ -419,9 +419,9 @@ let main () =
             function x ->
               let adrs = x * 3 in
               let m =
-                mono (Char.code buf.[adrs])
-                     (Char.code buf.[adrs + 1])
-                     (Char.code buf.[adrs + 2]) in
+                mono (Char.code (Bytes.get buf (adrs)))
+                     (Char.code (Bytes.get buf (adrs + 1)))
+                     (Char.code (Bytes.get buf (adrs + 2))) in
               for i = 0 to 2 do print_string (sprintf "%02x" m) done in
         if not conf.mirror
         then for x = x1 to x1 + w - 1 do print_pixel x done
