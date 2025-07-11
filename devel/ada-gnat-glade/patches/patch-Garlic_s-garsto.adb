$NetBSD: patch-Garlic_s-garsto.adb,v 1.1 2025/07/11 06:17:38 dkazankov Exp $

Get rid of Getenv
https://github.com/reznikmm/garlic/commit/4d16e8caddbcc83f6d37e14d657a6c8515466cc7

--- Garlic/s-garsto.adb.orig	2007-11-26 15:10:13.000000000 +0200
+++ Garlic/s-garsto.adb
@@ -33,8 +33,7 @@
 
 with Ada.Streams;    use Ada.Streams;
 
-with GNAT.HTable;
-with GNAT.OS_Lib;
+with System.HTable;
 with GNAT.Strings; use GNAT.Strings;
 
 with System.Garlic.Debug;      use System.Garlic.Debug;
@@ -59,12 +58,10 @@
       Key     : Debug_Key := Private_Debug_Key)
      renames Print_Debug_Info;
 
-   package OS  renames GNAT.OS_Lib;
-
    subtype Hash_Header is Natural range 0 .. 30;
 
-   function Hash  (F : OS.String_Access)      return Hash_Header;
-   function Equal (F1, F2 : OS.String_Access) return Boolean;
+   function Hash  (F : String_Access)      return Hash_Header;
+   function Equal (F1, F2 : String_Access) return Boolean;
    --  Hash and equality functions for hash table
 
    function Extract_Pkg_Name (Var_Name : String) return String;
@@ -88,11 +85,11 @@
    Max_Storages  : constant := 10;
    Storage_Table : array (First_Storage .. Max_Storages) of Shared_Data_Access;
 
-   package SST is new GNAT.HTable.Simple_HTable
+   package SST is new System.HTable.Simple_HTable
      (Header_Num => Hash_Header,
       Element    => Shared_Data_Access,
       No_Element => null,
-      Key        => OS.String_Access,
+      Key        => String_Access,
       Hash       => Hash,
       Equal      => Equal);
 
@@ -100,7 +97,7 @@
    -- Equal --
    -----------
 
-   function Equal (F1, F2 : OS.String_Access) return Boolean is
+   function Equal (F1, F2 : String_Access) return Boolean is
    begin
       return F1.all = F2.all;
    end Equal;
@@ -123,7 +120,7 @@
    -- Hash --
    ----------
 
-   function Hash (F : OS.String_Access) return Hash_Header is
+   function Hash (F : String_Access) return Hash_Header is
       N : Natural := 0;
 
    begin
