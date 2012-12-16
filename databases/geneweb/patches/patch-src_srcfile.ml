$NetBSD: patch-src_srcfile.ml,v 1.1 2012/12/16 22:39:47 dholland Exp $

Replace long-deprecated Stdpp.Exc_located with Ploc.Exc.

--- src/srcfile.ml~	2007-09-12 09:58:44.000000000 +0000
+++ src/srcfile.ml
@@ -192,7 +192,7 @@ END;
 
 value extract_date d =
   try Some (G.Entry.parse date (G.parsable (Stream.of_string d))) with
-  [ Stdpp.Exc_located _ (Stream.Error _ | Token.Error _) -> None ]
+  [ Ploc.Exc _ (Stream.Error _ | Token.Error _) -> None ]
 ;
 
 value string_of_start_date conf =
