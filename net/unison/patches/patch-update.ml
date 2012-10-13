$NetBSD: patch-update.ml,v 1.1 2012/10/13 09:05:12 wiz Exp $

r511 | vouillon | 2012-09-17 16:09:03 +0200 (Mon, 17 Sep 2012) | 3 lines

* Use hash function from OCaml 3.x for comparing archives, even when
  compiled with OCaml 4.x

--- update.ml.orig	2010-04-15 17:29:31.000000000 +0000
+++ update.ml
@@ -248,9 +248,9 @@ let rec checkArchive
                        (checkArchive false (n :: path) a h))
         children (Props.hash desc h)
   | ArchiveFile (desc, dig, _, ress) ->
-      Uutil.hash2 (Hashtbl.hash dig) (Props.hash desc h)
+      Uutil.hash2 (Uutil.hash dig) (Props.hash desc h)
   | ArchiveSymlink content ->
-      Uutil.hash2 (Hashtbl.hash content) h
+      Uutil.hash2 (Uutil.hash content) h
   | NoArchive ->
       135
 
