$NetBSD: patch-posix-supplement_to_ada_io.adb,v 1.3 2004/06/30 11:23:43 shannonjr Exp $

--- posix-supplement_to_ada_io.adb.orig	2002-10-24 02:03:52.000000000 -0600
+++ posix-supplement_to_ada_io.adb
@@ -113,6 +113,7 @@ package body POSIX.Supplement_to_Ada_IO 
 
       F   : System_File_Type;
       Ret : int;
+      pragma Warnings (Off, Ret);
 
    begin
       F := To_SFT (File);
@@ -126,6 +127,7 @@ package body POSIX.Supplement_to_Ada_IO 
 
       F   : System_File_Type;
       Ret : int;
+      pragma Warnings (Off, Ret);
 
    begin
       F := To_SFT (File);
