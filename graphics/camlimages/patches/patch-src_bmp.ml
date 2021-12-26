$NetBSD: patch-src_bmp.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/bmp.ml.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/bmp.ml
@@ -32,7 +32,7 @@ type bmp = {
    bmpFileHeader : bitmapfileheader;           (* Bytes <0  14< *)
    bmpInfoHeader : bitmapinfoheader;           (* Bytes <14 54< *)
    bmpRgbQuad : rgb array;                     (* Bytes <54 ... *)
-   bmpBytes : string;                          (* Bytes <bfOffBits ... *)
+   bmpBytes : Bytes.t;                         (* Bytes <bfOffBits ... *)
 }
 
 and bitmapfileheader = {
@@ -221,7 +221,7 @@ let load_colors bfh _bih ic =
 
 (* Loads image data when image has 8 bit depth *)
 let load_image8data bih ic =
- let bitmap = String.create (bih.biWidth * bih.biHeight) in
+ let bitmap = Bytes.create (bih.biWidth * bih.biHeight) in
  match bih.biCompression with
  | BI_RGB ->
      (* No compression : lines are stored in reverse order *)
@@ -232,7 +232,7 @@ let load_image8data bih ic =
        let bitmapindex = ref (i * bih.biWidth) in
        for j = 0 to pad - 1 do
          let c = Char.chr (read_byte ic) in
-         if j < bih.biWidth then bitmap.[!bitmapindex] <- c;
+         if j < bih.biWidth then Bytes.set bitmap !bitmapindex c;
          incr bitmapindex
          done
        done;
@@ -273,7 +273,7 @@ let load_image8data bih ic =
                   each of which contains the color index of a single pixel. *)
                for i = 0 to c - 1 do
                  let c1 = read_byte ic in
-                 bitmap.[!bitmapindex] <- Char.chr c1;
+                 Bytes.set bitmap !bitmapindex (Char.chr c1);
                  incr x;
                  incr bitmapindex
                done;
@@ -284,7 +284,7 @@ let load_image8data bih ic =
            (* Encoded mode *)
            let c1 = read_byte ic in
            for i = 0 to c - 1 do
-             bitmap.[!bitmapindex] <- Char.chr c1;
+             Bytes.set bitmap !bitmapindex (Char.chr c1);
              incr x;
              incr bitmapindex
            done
@@ -295,7 +295,7 @@ let load_image8data bih ic =
 ;;
 
 let load_image1data bih ic =
- let bitmap = String.create (bih.biWidth * bih.biHeight) in
+ let bitmap = Bytes.create (bih.biWidth * bih.biHeight) in
  let c = ref 0 in
  (* each scan line 'w', is padded to be a multiple of 32 *)
  let pad = ((bih.biWidth + 31) / 32) * 32 in
@@ -311,7 +311,7 @@ let load_image1data bih ic =
       end;
      if j < bih.biWidth then
       begin
-       bitmap.[!bitmapindex] <- if !c land 0x80 <> 0 then '\001' else '\000';
+       Bytes.set bitmap !bitmapindex (if !c land 0x80 <> 0 then '\001' else '\000');
        incr bitmapindex;
        c := !c lsl 1;
       end;
@@ -322,7 +322,7 @@ let load_image1data bih ic =
 ;;
 
 let load_image4data bih ic =
- let bitmap = String.create (bih.biWidth * bih.biHeight) in
+ let bitmap = Bytes.create (bih.biWidth * bih.biHeight) in
  match bih.biCompression with
  | BI_RGB ->
     (* 'w' is padded to be a multiple of 8 pixels (32 bits) *)
@@ -341,7 +341,7 @@ let load_image4data bih ic =
           end;
         if j < bih.biWidth then
           begin
-          bitmap.[!bitmapindex] <- Char.chr ((!c land 0xf0) lsr 4);
+          Bytes.set bitmap !bitmapindex (Char.chr ((!c land 0xf0) lsr 4));
           incr bitmapindex;
           c := !c lsl 4
           end;
@@ -380,7 +380,7 @@ let load_image4data bih ic =
               for i = 0 to c - 1 do
                 if i land 1 = 0 then c1 := read_byte ic;
                 let c = if i land 1 <> 0 then !c1 else !c1 lsr 4 in
-                bitmap.[!bitmapindex] <- Char.chr (c land 0x0F);
+                Bytes.set bitmap !bitmapindex (Char.chr (c land 0x0F));
                 incr x;
                 incr bitmapindex
               done;
@@ -395,7 +395,7 @@ let load_image4data bih ic =
           and col2 = (c1 lsr 4) land 0x0F in
           for i = 0 to c - 1 do
             let c = if i land 1 <> 0 then col1 else col2 in
-            bitmap.[!bitmapindex] <- Char.chr c;
+            Bytes.set bitmap !bitmapindex (Char.chr c);
             incr x;
             incr bitmapindex
           done
@@ -407,15 +407,15 @@ let load_image4data bih ic =
 
 let load_image24data bih ic =
   (* Bitmap is a string of RGB bytes *)
-  let bitmap = String.create ((bih.biWidth * bih.biHeight) * 3) in
+  let bitmap = Bytes.create ((bih.biWidth * bih.biHeight) * 3) in
   let pad = (4 - ((bih.biWidth * 3) mod 4)) land 0x03 in
   let pp = ref 0 in
   for i = bih.biHeight - 1 downto 0 do
     pp := (i * bih.biWidth * 3);
     for j = 0 to bih.biWidth - 1 do
-      bitmap.[!pp + 2] <- Char.chr (read_byte ic);   (* Blue *)
-      bitmap.[!pp + 1] <- Char.chr (read_byte ic);   (* Green *)
-      bitmap.[!pp] <- Char.chr (read_byte ic);     (* Red *)
+      Bytes.set bitmap (!pp + 2) (Char.chr (read_byte ic));   (* Blue *)
+      Bytes.set bitmap (!pp + 1) (Char.chr (read_byte ic));   (* Green *)
+      Bytes.set bitmap (!pp    ) (Char.chr (read_byte ic));   (* Red *)
       pp := !pp + 3
     done;
     for j = 0 to pad - 1 do skip_byte ic done;
@@ -478,13 +478,15 @@ let image_of_bmp = function
    bmpInfoHeader = bih;
    bmpRgbQuad = colormap;
    bmpBytes = bitmap; } ->
+   (* safe: we pass it only to create_with, which copies it *)
+   let bitmap' = Bytes.unsafe_to_string bitmap in
    match bih.biBitCount with
    | ColorM ->
-       Rgb24 (Rgb24.create_with bih.biWidth bih.biHeight [] bitmap)
+       Rgb24 (Rgb24.create_with bih.biWidth bih.biHeight [] bitmap')
    | _ ->
        Index8
          (Index8.create_with bih.biWidth bih.biHeight []
-            { map = colormap; max = 256; } (-1) bitmap)
+            { map = colormap; max = 256; } (-1) bitmap')
 ;;
 
 let load fname _opts = image_of_bmp (read_bmp_file fname);;
@@ -661,7 +663,7 @@ let write_image1data bmp oc =
    if count = 8 then begin
      write_byte oc accu;
      if x <= lim then write_line x 0 0 end else
-   let cur = bitmap.[x] in
+   let cur = Bytes.get bitmap x in
    let chunk = Char.code cur lsl (7 - count) in
    let new_accu = chunk + accu in
    if x = lim then write_byte oc new_accu
@@ -693,9 +695,9 @@ let write_image24data bmp oc =
   let start = i * width * 3 in
   let lim = (i + 1) * width * 3 - 1 in
   let rec write_line x =
-   write_byte oc (Char.code bitmap.[x + 2]);   (* Blue *)
-   write_byte oc (Char.code bitmap.[x + 1]);   (* Green *)
-   write_byte oc (Char.code bitmap.[x]);       (* Red *)
+   write_byte oc (Char.code (Bytes.get bitmap (x + 2)));   (* Blue *)
+   write_byte oc (Char.code (Bytes.get bitmap (x + 1)));   (* Green *)
+   write_byte oc (Char.code (Bytes.get bitmap (x)));       (* Red *)
    let new_x = x + 3 in
    if new_x < lim then write_line new_x in
 
@@ -730,7 +732,7 @@ let write_image4data bmp oc =
       if count = 2 then begin
        write_byte oc accu;
        if x <= lim then write_line x 0 0 end else
-      let cur = bitmap.[x] in
+      let cur = Bytes.get bitmap x in
       let chunk = Char.code cur lsl (4 - count) in
       let new_accu = chunk + accu in
       if x = lim then write_byte oc new_accu
@@ -755,7 +757,7 @@ let write_image4data bmp oc =
      let start = i * width in
      let lim = (i + 1) * width - 1 in
      let rec write_line x count pred =
-      let cur = bitmap.[x] in
+      let cur = Bytes.get bitmap x in
       if cur = pred then
        if x = lim then write_rle4 oc (count + 1) pred
        else write_line (x + 1) (count + 1) pred
@@ -764,7 +766,7 @@ let write_image4data bmp oc =
        if x = lim then write_rle4 oc 1 cur
        else write_line (x + 1) 1 cur
       end in
-     write_line start 0 bitmap.[start];
+     write_line start 0 (Bytes.get bitmap start);
      write_end_of_scan_line oc;
      (* No padding in this mode *)
     done;
@@ -794,7 +796,7 @@ let write_image8data bmp oc =
      let start = i * width in
      let lim = (i + 1) * width - 1 in
      let rec write_line x =
-      let cur = bitmap.[x] in
+      let cur = Bytes.get bitmap x in
       write_byte oc (Char.code cur);
       if x < lim then write_line (x + 1) in
 
@@ -817,7 +819,7 @@ let write_image8data bmp oc =
      let start = i * width in
      let lim = (i + 1) * width - 1 in
      let rec write_line x count pred =
-      let cur = bitmap.[x] in
+      let cur = Bytes.get bitmap x in
       if cur = pred then
        if x = lim then write_rle oc (count + 1) pred
        else write_line (x + 1) (count + 1) pred
@@ -826,7 +828,7 @@ let write_image8data bmp oc =
        if x = lim then write_rle oc 1 cur
        else write_line (x + 1) 1 cur
       end in
-     write_line start 0 bitmap.[start];
+     write_line start 0 (Bytes.get bitmap start);
      write_end_of_scan_line oc;
      (* No padding in this mode *)
     done;
@@ -851,7 +853,7 @@ let bmp_of_image img =
   | Rgb24 bitmap ->
     let biW = bitmap.Rgb24.width
     and biH = bitmap.Rgb24.height
-    and data = Rgb24.dump bitmap in
+    and data = Rgb24.dumpbytes bitmap in
     let bfh = {
       (* WORD *) bfType = 19778 (* BM *);
       (* DWORD *) bfSize = -1 (* Unknown to be updated *);
@@ -892,7 +894,7 @@ let bmp_of_image img =
     let colormap = bitmap.Index8.colormap.map
     and biW = bitmap.Index8.width
     and biH = bitmap.Index8.height
-    and data = Index8.dump bitmap in
+    and data = Index8.dumpbytes bitmap in
     let bfh = {
       (* WORD *) bfType = 19778 (* BM *);
       (* DWORD *) bfSize = -1 (* Unknown to be updated *);
