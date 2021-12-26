$NetBSD: patch-src_bitmap.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

Sort.list is so old it's not even in the deprecations section of the
manual any more. Use List.sort.

--- src/bitmap.ml.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/bitmap.ml
@@ -20,7 +20,7 @@ let maximum_block_size = ref (!maximum_l
 (* see Temp to set temp file directory *)
 
 type block_data =
-   | InMemory of string
+   | InMemory of Bytes.t
    | Swapped
    | Destroyed;;
 
@@ -35,9 +35,9 @@ type block = {
 
 let swappable_blocks = ref [];;
 
-(* wrapped String.create *)
-let string_create s =
-  try String.create s with Invalid_argument _ -> raise Out_of_memory;;
+(* wrapped Bytes.create *)
+let bytes_create s =
+  try Bytes.create s with Invalid_argument _ -> raise Out_of_memory;;
 
 module Block = struct
   type t = {
@@ -67,7 +67,7 @@ module Make(B:Bitdepth) = struct
     blocks_x : int;
     blocks_y : int;
     data : block array array;
-    access : int -> int -> (string * int);
+    access : int -> int -> (Bytes.t * int);
     };;
 
   (****************************************************************************)
@@ -92,20 +92,20 @@ module Make(B:Bitdepth) = struct
            if blk == blk' then st else blk' :: st)
         !swappable_blocks [];;
 
-  let fill_string buf init =
-    (* fill string with init quickly (hopefully) *)
-    let fulllength = String.length buf in
+  let fill_bytes (buf: Bytes.t) (init: string) =
+    (* fill a Bytes with init quickly (hopefully) *)
+    let fulllength = Bytes.length buf in
     let halflength = fulllength / 2 in
     let rec sub = function
       | 0 ->
         let len = String.length init in
-        String.unsafe_blit init 0 buf 0 len;
+        Bytes.unsafe_blit_string init 0 buf 0 len;
         sub len
       | x when x <= halflength ->
-        String.unsafe_blit buf 0 buf x x;
+        Bytes.unsafe_blit buf 0 buf x x;
         sub (x * 2)
       | x (* when x > halflength *) ->
-        String.unsafe_blit buf 0 buf x (fulllength - x) in
+        Bytes.unsafe_blit buf 0 buf x (fulllength - x) in
     sub 0;;
 
   let check_init init =
@@ -115,7 +115,7 @@ module Make(B:Bitdepth) = struct
         then failwith "bitmap fill value is incorrect"
     | None -> ();;
 
-  let memory width height init =
+  let memory width height (init: string option) =
     (* try to have it whole in memory *)
 
     check_init init;
@@ -137,11 +137,11 @@ module Make(B:Bitdepth) = struct
 	in
 	(* CR jfuruse: check overflow *)
  	let size = width * height * bytes_per_pixel in
-	string_create size, size, height)
+	bytes_create size, size, height)
     in
     let bufs = Array.map (fun (buf, _, _) -> buf) buf_size_heights in
     begin match init with
-    | Some v -> Array.iter (fun s -> fill_string s v) bufs;
+    | Some v -> Array.iter (fun s -> fill_bytes s v) bufs;
     | None -> ()
     end;
     { width = width;
@@ -186,7 +186,7 @@ module Make(B:Bitdepth) = struct
 
   let swap_out_eldest words =
     let sorted =
-      Sort.list (fun b1 b2 -> b1.last_used < b2.last_used) !swappable_blocks in
+      List.sort (fun b1 b2 -> compare b1.last_used b2.last_used) !swappable_blocks in
     let rec swapper sorted i =
      match sorted with
       | [] -> ()
@@ -213,7 +213,7 @@ module Make(B:Bitdepth) = struct
           debugs ("swap in "^fname);
           require size;
           let ic = open_in_bin fname in
-          let s = string_create size in
+          let s = bytes_create size in
           really_input ic s 0 size;
           close_in ic;
           blk.block_data <- InMemory s;
@@ -231,9 +231,9 @@ module Make(B:Bitdepth) = struct
     (* CR jfuruse: check overflow *)
     let size = bytes_per_pixel * width * height in
     require size;
-    let s = string_create size in
+    let s = bytes_create size in
     begin match init with
-    | Some v -> fill_string s v
+    | Some v -> fill_bytes s v
     | None -> ()
     end;
     let blk =
@@ -271,13 +271,13 @@ module Make(B:Bitdepth) = struct
               height / p + (if height mod p <> 0 then 1 else 0) in
         try
 	  (* CR jfuruse: check overflow *)
-          p, string_create
+          p, bytes_create
                (block_size_width * block_size_height * bytes_per_pixel)
         with
         | Out_of_memory -> alloc_test_block (p + 1) in
       let blocks, test_block = alloc_test_block (get_block_size 1) in
       (* use the block so that it is not GCed too early *)
-      test_block.[0] <- '0';
+      Bytes.set test_block 0 '0';
 
       (* Create bitmap *)
       let blocks_x = blocks
@@ -336,6 +336,7 @@ module Make(B:Bitdepth) = struct
     end;;
 
   let create_with width height buf =
+    let bufcopy = Bytes.of_string buf in
     { width = width;
       height = height;
       block_size_width = width;
@@ -345,13 +346,13 @@ module Make(B:Bitdepth) = struct
       data =
         [| [| { block_width = width;
                 block_height = height;
-                block_data = InMemory buf;
+                block_data = InMemory bufcopy;
 		(* CR jfuruse: check overflow *)
                 block_size = width * height * bytes_per_pixel;
                 last_used = 0.0;
                 swap = None;
                } |] |];
-      access = (fun x y -> buf, (y * width + x) * bytes_per_pixel);
+      access = (fun x y -> bufcopy, (y * width + x) * bytes_per_pixel);
     };;
 
   let create_with_scanlines width height scanlines =
@@ -373,6 +374,7 @@ module Make(B:Bitdepth) = struct
 	assert false
       end
     done;
+    let scanlines_copy = Array.map Bytes.of_string scanlines in
     { width = width;
       height = height;
       block_size_width = width;
@@ -383,11 +385,11 @@ module Make(B:Bitdepth) = struct
 	[| Array.mapi (fun y scanline ->
 	  { block_width = width;
             block_height = 1;
-            block_data = InMemory scanlines.(y);
+            block_data = InMemory scanlines_copy.(y);
             block_size = block_size;
             last_used = 0.0;
             swap = None }) scanlines |];
-      access = (fun x y -> scanlines.(y), x * bytes_per_pixel);
+      access = (fun x y -> scanlines_copy.(y), x * bytes_per_pixel);
     };;
 
   (****************************************************************************)
@@ -410,13 +412,14 @@ module Make(B:Bitdepth) = struct
       let src = swap_in blk in
       let size = w * bytes_per_pixel in
       let adrs = (blk.block_width * y' + x) * bytes_per_pixel in
-      let str = string_create size in
-      String.unsafe_blit src adrs str 0 size;
-      str
+      let str = bytes_create size in
+      Bytes.unsafe_blit src adrs str 0 size;
+      (* safe: just created str and copied to it *)
+      Bytes.unsafe_to_string str
     | _, _ ->
       let bly = y / t.block_size_height in
       let y' = y mod t.block_size_height in
-      let str = string_create (w * bytes_per_pixel) in
+      let str = bytes_create (w * bytes_per_pixel) in
       let blx_start = x / t.block_size_width in
       let blx_last = (x + w - 1) / t.block_size_width in
       for blx = blx_start to blx_last do
@@ -433,9 +436,10 @@ module Make(B:Bitdepth) = struct
         let offset =
           if blx = blx_start then 0
           else (t.block_size_width * blx - x) * bytes_per_pixel in
-        String.unsafe_blit src adrs str offset size
+        Bytes.unsafe_blit src adrs str offset size
       done;
-      str;;
+      (* safe: just created str and copied to it *)
+      Bytes.unsafe_to_string str;;
 
   let set_strip t x y w str =
     (* No region checks for performance. You should wrap this to make safe
@@ -505,28 +509,29 @@ module Make(B:Bitdepth) = struct
 
   (* dump : of course this does not work for large images *)
 
-  let dump t =
+  (* always produces a fresh bytes, not a pointer into the image *)
+  let dumpbytes t =
     (* CR jfuruse: check overflow *)
     let size = bytes_per_pixel * t.width * t.height in
     match t.blocks_x, t.blocks_y with
-    | 1, 1 -> swap_in t.data.(0).(0)
+    | 1, 1 -> Bytes.copy (swap_in t.data.(0).(0))
     | 1, h ->
-      let s = string_create size in
+      let s = bytes_create size in
       let scanline_size = bytes_per_pixel * t.width in
       for y = 0 to h - 1 do
         let str = swap_in t.data.(0).(y) in
-        String.unsafe_blit str 0 s (scanline_size * y) scanline_size
+        Bytes.unsafe_blit str 0 s (scanline_size * y) scanline_size
       done;
       s
     | w, h ->
-      let s = string_create size in
+      let s = bytes_create size in
       for x = 0 to w - 1 do
         for y = 0 to h - 1 do
           let blk = t.data.(x).(y) in
           let str = swap_in blk in
           let scanline_size = bytes_per_pixel * blk.block_width in
           for i = 0 to blk.block_height - 1 do
-            String.unsafe_blit str (scanline_size * i)
+            Bytes.unsafe_blit str (scanline_size * i)
               s (((y * t.block_size_height + i) * t.width +
                     x * t.block_size_width) * bytes_per_pixel)
               scanline_size
@@ -535,6 +540,9 @@ module Make(B:Bitdepth) = struct
       done;
       s;;
 
+  (* safe: dumpbytes always returns a fresh bytes *)
+  let dump t = Bytes.unsafe_to_string (dumpbytes t);;
+
   (* sub-bitmap *)
   let sub t x y w h =
     Region.check t.width t.height x y;
@@ -575,5 +583,6 @@ module Make(B:Bitdepth) = struct
       height = h;
       x = at_x;
       y = at_y;
-      dump = swap_in blk }
+      (* copy the data for return *)
+      dump = Bytes.to_string (swap_in blk) }
 end;;
