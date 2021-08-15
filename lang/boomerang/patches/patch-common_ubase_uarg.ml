$NetBSD: patch-common_ubase_uarg.ml,v 1.1 2021/08/15 06:38:38 dholland Exp $

Silence warning about archaic syntax.

--- common/ubase/uarg.ml~	2007-03-26 13:07:39.000000000 +0000
+++ common/ubase/uarg.ml
@@ -66,7 +66,7 @@ let parse speclist anonfun errmsg =
   incr current;
   while !current < l do
     let ss = Sys.argv.(!current) in
-    if String.length ss >= 1 & String.get ss 0 = '-' then begin
+    if String.length ss >= 1 && String.get ss 0 = '-' then begin
       let args = Util.splitIntoWords ss '=' in
       let s = Safelist.nth args 0 in
       let arg conv mesg =
