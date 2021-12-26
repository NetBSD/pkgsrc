$NetBSD: patch-src_bmp.mli,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/bmp.mli~	2011-06-22 18:04:32.000000000 +0000
+++ src/bmp.mli
@@ -39,7 +39,7 @@ type bmp = {
    bmpFileHeader : bitmapfileheader;           (** Bytes <0  14< *)
    bmpInfoHeader : bitmapinfoheader;           (** Bytes <14 54< *)
    bmpRgbQuad : Images.rgb array;              (** Bytes <54 ... *)
-   bmpBytes : string;                          (** Bytes <bfOffBits ... *)
+   bmpBytes : Bytes.t;                         (** Bytes <bfOffBits ... *)
 }
 
 and bitmapfileheader = {
