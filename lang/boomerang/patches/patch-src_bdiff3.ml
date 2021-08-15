$NetBSD: patch-src_bdiff3.ml,v 1.1 2021/08/15 06:38:38 dholland Exp $

Silence compiler warning about archaic syntax.

--- src/bdiff3.ml~	2009-08-03 16:53:28.000000000 +0000
+++ src/bdiff3.ml
@@ -83,7 +83,7 @@ module Make(A: Diff3Arg) = struct
            lcs_oa.(i)) 
       lcs_oa;
     let rec find_matches i j l = 
-      if (i=0) or (j=0) then l
+      if (i=0) || (j=0) then l
       else match lcs_aux.(i).(j) with  
         | Diag -> find_matches (i-1) (j-1) ((i-1,j-1)::l)  
         | Top  -> find_matches (i-1) j l    
