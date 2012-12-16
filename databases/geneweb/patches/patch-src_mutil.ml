$NetBSD: patch-src_mutil.ml,v 1.1 2012/12/16 22:39:47 dholland Exp $

Insert missing semicolons demanded by ocaml4.

--- src/mutil.ml~	2007-08-04 07:22:30.000000000 +0000
+++ src/mutil.ml
@@ -95,7 +95,7 @@ value decline case s =
       | '>' -> String.sub s ibeg (i + 1 - ibeg) ^ loop (i + 1) (i + 1)
       | _ -> loop ibeg (i + 1) ]
 ;
-end ELSE declare
+end; ELSE declare
 (* [decline] has been deprecated since version 5.00
    compatibility code: *)
 value colon_to_at_word s ibeg iend =
@@ -158,7 +158,7 @@ value decline case s =
     (if not (String.contains s ':') then s else colon_to_at s)
 ;
 (* end compatibility code *)
-end END;
+end; END;
 
 value nominative s =
   match rindex s ':' with
