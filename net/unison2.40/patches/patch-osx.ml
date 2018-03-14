$NetBSD: patch-osx.ml,v 1.1 2018/03/14 11:16:15 dholland Exp $

Fix build with ocaml 4.06.

--- osx.ml.orig	2010-10-08 15:44:59.000000000 +0000
+++ osx.ml
@@ -60,7 +60,7 @@ let doubleVersion = "\000\002\000\000"
 let doubleFiller = String.make 16 '\000'
 let ressource_fork_empty_tag = "This resource fork intentionally left blank   "
 let finfoLength = 32L
-let emptyFinderInfo () = String.make 32 '\000'
+let emptyFinderInfo () = Bytes.make 32 '\000'
 let empty_ressource_fork =
   "\000\000\001\000" ^
   "\000\000\001\000" ^
@@ -108,13 +108,13 @@ let getID buf ofs =
     | _ -> `UNKNOWN
 
 let setInt4 v =
-  let s = String.create 4 in
+  let s = Bytes.create 4 in
   let set i =
-    s.[i] <-
-      Char.chr (Int64.to_int (Int64.logand 255L
-                               (Int64.shift_right v (24 - 8 * i)))) in
+    Bytes.set s i
+      (Char.chr (Int64.to_int (Int64.logand 255L
+                               (Int64.shift_right v (24 - 8 * i))))) in
   set 0; set 1; set 2; set 3;
-  s
+  Bytes.to_string s
 
 let fail dataFspath dataPath doubleFspath msg =
   debug (fun () -> Util.msg "called 'fail'");
@@ -126,13 +126,13 @@ let fail dataFspath dataPath doubleFspat
               (Fspath.toPrintString (Fspath.concat dataFspath dataPath)) msg))
 
 let readDouble dataFspath dataPath doubleFspath inch len =
-  let buf = String.create len in
+  let buf = Bytes.create len in
   begin try
     really_input inch buf 0 len
   with End_of_file ->
     fail dataFspath dataPath doubleFspath "truncated"
   end;
-  buf
+  Bytes.to_string buf
 
 let readDoubleFromOffset dataFspath dataPath doubleFspath inch offset len =
   LargeFile.seek_in inch offset;
@@ -223,7 +223,13 @@ let extractInfo typ info =
   let xflags = String.sub info 24 2 in
   let typeCreator = String.sub info 0 8 in
   (* Ignore hasBeenInited flag *)
+
+(*
   flags.[0] <- Char.chr (Char.code flags.[0] land 0xfe);
+*)
+  let fix i c = if i = 0 then Char.chr (Char.code c land 0xfe) else c in
+  let flags = String.mapi fix flags in
+
   (* If the extended flags should be ignored, clear them *)
   let xflags =
     if Char.code xflags.[0] land 0x80 <> 0 then "\000\000" else xflags
@@ -266,9 +272,9 @@ let getFileInfos dataFspath dataPath typ
                    protect (fun () ->
                      LargeFile.seek_in inch (Int64.add offset 16L);
                      let len = String.length ressource_fork_empty_tag in
-                     let buf = String.create len in
+                     let buf = Bytes.create len in
                      really_input inch buf 0 len;
-                     buf = ressource_fork_empty_tag)
+                     Bytes.to_string buf = ressource_fork_empty_tag)
                      (fun () -> close_in_noerr inch)
                 then
                   (0L, 0L)
@@ -343,7 +349,7 @@ let setFileInfos dataFspath dataPath fin
     try
       let p = Fspath.toSysPath (Fspath.concat dataFspath dataPath) in
       let (fullFinfo, _) = getFileInfosInternal p false in
-      setFileInfosInternal p (insertInfo fullFinfo finfo)
+      setFileInfosInternal p (Bytes.to_string (insertInfo (Bytes.of_string fullFinfo) finfo))
     with Unix.Unix_error ((Unix.EOPNOTSUPP | Unix.ENOSYS), _, _) ->
       (* Not an HFS volume.  Look for an AppleDouble file *)
       let (workingDir, realPath) = Fspath.findWorkingDir dataFspath dataPath in
@@ -367,7 +373,7 @@ let setFileInfos dataFspath dataPath fin
             Fs.open_out_gen [Open_wronly; Open_binary] 0o600 doubleFspath in
           protect
             (fun () ->
-               writeDoubleFromOffset outch ofs (insertInfo fullFinfo finfo);
+               writeDoubleFromOffset outch ofs (Bytes.to_string (insertInfo (Bytes.of_string fullFinfo) finfo));
                close_out outch)
             (fun () ->
                close_out_noerr outch);
@@ -406,7 +412,7 @@ let setFileInfos dataFspath dataPath fin
             output_string outch "\000\000\000\002"; (* Ressource fork *)
             output_string outch "\000\000\014\226"; (* offset *)
             output_string outch "\000\000\001\030"; (* length *)
-            output_string outch (insertInfo (emptyFinderInfo ()) finfo);
+            output_bytes outch (insertInfo (emptyFinderInfo ()) finfo);
             output_string outch (empty_attribute_chunk ());
                                                     (* extended attributes *)
             output_string outch empty_ressource_fork;
@@ -517,7 +523,7 @@ let openRessOut fspath path length =
 (* FIX: should check for overflow! *)
         output_string outch (setInt4 (Uutil.Filesize.toInt64 length));
                                                 (* length *)
-        output_string outch (emptyFinderInfo ());
+        output_bytes outch (emptyFinderInfo ());
         output_string outch (empty_attribute_chunk ());
                                                 (* extended attributes *)
         flush outch)
