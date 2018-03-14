$NetBSD: patch-uicommon.ml,v 1.1 2018/03/14 10:16:03 dholland Exp $

Fix build with ocaml 4.06.

--- uicommon.ml~	2009-05-28 09:23:33.000000000 +0000
+++ uicommon.ml
@@ -356,16 +356,16 @@ let dangerousPathMsg dangerousPaths =
 
 let quote s =
   let len = String.length s in
-  let buf = String.create (2 * len) in
+  let buf = Bytes.create (2 * len) in
   let pos = ref 0 in
   for i = 0 to len - 1 do
     match s.[i] with
       '*' | '?' | '[' | '{' | '}' | ',' | '\\' as c ->
-        buf.[!pos] <- '\\'; buf.[!pos + 1] <- c; pos := !pos + 2
+        Bytes.set buf !pos '\\'; Bytes.set buf (!pos + 1) c; pos := !pos + 2
     | c ->
-        buf.[!pos] <- c; pos := !pos + 1
+        Bytes.set buf !pos c; pos := !pos + 1
   done;
-  "{" ^ String.sub buf 0 !pos ^ "}"
+  "{" ^ Bytes.to_string (Bytes.sub buf 0 !pos) ^ "}"
 
 let ignorePath path = "Path " ^ quote (Path.toString path)
 
