$NetBSD: patch-src_gif.mli,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/gif.mli.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/gif.mli
@@ -85,7 +85,7 @@ val dGifOpenFileName : string -> screen_
 val dGifCloseFile : in_channel -> unit;;
 val dGifGetRecordType : in_channel -> record_type;;
 val dGifGetImageDesc : in_channel -> gif_desc;;
-val dGifGetLine : in_channel -> string;;
+val dGifGetLine : in_channel -> Bytes.t;;
 val dGifGetExtension : in_channel -> int * string list;;
 
 val eGifOpenFileName : string -> out_channel;;
