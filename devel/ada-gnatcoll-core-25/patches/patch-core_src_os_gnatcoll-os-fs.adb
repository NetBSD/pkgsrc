$NetBSD: patch-core_src_os_gnatcoll-os-fs.adb,v 1.1 2025/10/07 20:45:10 dkazankov Exp $

Fix portability

--- core/src/os/gnatcoll-os-fs.adb.orig	2024-09-24 12:28:32.000000000 +0300
+++ core/src/os/gnatcoll-os-fs.adb
@@ -80,7 +80,7 @@
       Result : Integer;
    begin
       Result := Unsafe_Read (FD, Buffer (Buffer'First)'Address, Buffer'Length);
-      if Result < 0 then
+      if Result = -1 then
          raise OS_Error with "read error";
       end if;
 
@@ -109,7 +109,7 @@
 
       Result := C_Read (FD, Buffer (First)'Address, size_t (Last - First + 1));
 
-      if Result < 0 then
+      if Result = -1 then
          raise OS_Error with "read error";
       end if;
 
@@ -201,7 +201,7 @@
    begin
       Result := C_Write (FD, Buffer (Buffer'First)'Address, Buffer'Length);
 
-      if Result < 0 then
+      if Result = -1 then
          raise OS_Error with "write error";
       end if;
 
