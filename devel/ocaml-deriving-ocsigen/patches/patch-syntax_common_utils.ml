$NetBSD: patch-syntax_common_utils.ml,v 1.1 2018/01/10 14:57:35 jaapb Exp $

Patch to compile with safe-string.
--- syntax/common/utils.ml.orig	2016-05-25 16:51:52.000000000 +0000
+++ syntax/common/utils.ml
@@ -216,7 +216,7 @@ let random_id length =
     for i = 0 to length - 1 do
       Bytes.set s i idchars.[Random.int nidchars]
     done;
-    s
+    Bytes.to_string s
 
 (* The function used in OCaml to convert variant labels to their
    integer representations.  The formula is given in Jacques
