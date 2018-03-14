$NetBSD: patch-uitext.ml,v 1.1 2018/03/14 11:16:15 dholland Exp $

Fix build with ocaml 4.06.

--- uitext.ml~	2010-04-15 17:29:31.000000000 +0000
+++ uitext.ml
@@ -112,11 +112,12 @@ let getInput () =
         (* We cannot used buffered I/Os under Windows, as character
            '\r' is not passed through (probably due to the code that
            turns \r\n into \n) *)
-        let s = String.create 1 in
+        let s = Bytes.create 1 in
         let n = Unix.read Unix.stdin s 0 1 in
         if n = 0 then raise End_of_file;
-        if s.[0] = '\003' then raise Sys.Break;
-        s.[0]
+        let c = Bytes.get s 0 in
+        if c = '\003' then raise Sys.Break;
+        c
       in
       funs.System.startReading ();
       let c = input_char () in
