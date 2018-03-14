$NetBSD: patch-osx.ml,v 1.1 2018/03/14 10:16:03 dholland Exp $

Fix build with ocaml 4.06.

--- osx.ml~	2009-06-18 08:36:04.000000000 +0000
+++ osx.ml
@@ -56,12 +56,12 @@ let appleDoubleFile fspath path =
   let len = String.length f in
   try
     let i = 1 + String.rindex f '/' in
-    let res = String.create (len + 2) in
+    let res = Bytes.create (len + 2) in
     String.blit f 0 res 0 i;
-    res.[i] <- '.';
-    res.[i + 1] <- '_';
+    Bytes.set res i '.';
+    Bytes.set res (i + 1) '_';
     String.blit f i res (i + 2) (len - i);
-    res
+    Bytes.to_string res
   with Not_found ->
     assert false
 
@@ -70,7 +70,7 @@ let doubleVersion = "\000\002\000\000"
 let doubleFiller = String.make 16 '\000'
 let ressource_fork_empty_tag = "This resource fork intentionally left blank   "
 let finfoLength = 32L
-let emptyFinderInfo () = String.make 32 '\000'
+let emptyFinderInfo () = Bytes.make 32 '\000'
 let empty_ressource_fork =
   "\000\000\001\000" ^
   "\000\000\001\000" ^
@@ -118,26 +118,26 @@ let getID buf ofs =
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
 
 let fail path msg =
   raise (Util.Transient
            (Format.sprintf "Malformed AppleDouble file '%s' (%s)" path msg))
 
 let readDouble path inch len =
-  let buf = String.create len in
+  let buf = Bytes.create len in
   begin try
     really_input inch buf 0 len
   with End_of_file ->
     fail path "truncated"
   end;
-  buf
+  Bytes.to_string buf
 
 let readDoubleFromOffset path inch offset len =
   LargeFile.seek_in inch offset;
@@ -226,7 +226,13 @@ let extractInfo typ info =
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
@@ -265,9 +271,9 @@ let getFileInfos fspath path typ =
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
@@ -341,7 +347,7 @@ let setFileInfos fspath path finfo =
       let (fullFinfo, _) =
         getFileInfosInternal (Fspath.concatToString fspath path) false in
       setFileInfosInternal (Fspath.concatToString fspath path)
-        (insertInfo fullFinfo finfo)
+        (Bytes.to_string (insertInfo (Bytes.of_string fullFinfo) finfo))
     with Unix.Unix_error ((Unix.EOPNOTSUPP | Unix.ENOSYS), _, _) ->
       (* Not an HFS volume.  Look for an AppleDouble file *)
       let (fspath, path) = Fspath.findWorkingDir fspath path in
@@ -363,7 +369,7 @@ let setFileInfos fspath path finfo =
           protect
             (fun () ->
                writeDoubleFromOffset doublePath outch ofs
-                 (insertInfo fullFinfo finfo);
+                 (Bytes.to_string (insertInfo (Bytes.of_string fullFinfo) finfo));
                close_out outch)
             (fun () ->
                close_out_noerr outch);
@@ -400,7 +406,7 @@ let setFileInfos fspath path finfo =
             output_string outch "\000\000\000\002"; (* Ressource fork *)
             output_string outch "\000\000\014\226"; (* offset *)
             output_string outch "\000\000\001\030"; (* length *)
-            output_string outch (insertInfo (emptyFinderInfo ()) finfo);
+            output_bytes outch (insertInfo (emptyFinderInfo ()) finfo);
             output_string outch (empty_attribute_chunk ());
                                                     (* extended attributes *)
             output_string outch empty_ressource_fork;
@@ -509,7 +515,7 @@ let openRessOut fspath path length =
         output_string outch "\000\000\014\226"; (* offset *)
         output_string outch (setInt4 (Uutil.Filesize.toInt64 length));
                                                 (* length *)
-        output_string outch (emptyFinderInfo ());
+        output_bytes outch (emptyFinderInfo ());
         output_string outch (empty_attribute_chunk ());
                                                 (* extended attributes *)
         flush outch)
