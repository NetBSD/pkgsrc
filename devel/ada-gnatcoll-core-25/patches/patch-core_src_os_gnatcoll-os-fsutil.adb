$NetBSD: patch-core_src_os_gnatcoll-os-fsutil.adb,v 1.1 2025/10/07 20:45:10 dkazankov Exp $

There is no point in continuing if this is a directory.
It also doesn't work correctly on NetBSD.

--- core/src/os/gnatcoll-os-fsutil.adb.orig	2024-09-24 12:28:32.000000000 +0300
+++ core/src/os/gnatcoll-os-fsutil.adb
@@ -71,6 +71,7 @@
       return Result_Type
    is
       FD      : FS.File_Descriptor;
+      FA      : File_Attributes;
       Context : State_Type;
       N       : Integer;
       Buffer  : String_Access;
@@ -84,6 +85,12 @@
          raise OS_Error with "Failed to open " & String (Path);
       end if;
 
+      FA := Fstat (FD);
+      if Is_Directory (FA) then
+         FS.Close (FD);
+         raise OS_Error with String (Path) & " is a directory";
+      end if;
+
       Buffer := new String (1 .. Buffer_Size);
 
       begin
