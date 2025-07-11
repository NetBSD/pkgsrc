$NetBSD: patch-Dist_xe__utils.adb,v 1.1 2025/07/11 06:17:38 dkazankov Exp $

Fix some compilation warnings
https://github.com/reznikmm/garlic/commit/b738f20db65add57f817f952a625df73bef0710e
Calculate gnat driver name by gnatdist name
Also fix -cargs option passing
https://github.com/reznikmm/garlic/commit/1bca5670b0f08ab8e3902441a46bc1c7a9fdf059

--- Dist/xe_utils.adb.orig	2007-11-26 15:10:13.000000000 +0200
+++ Dist/xe_utils.adb
@@ -24,6 +24,7 @@
 --                                                                          --
 ------------------------------------------------------------------------------
 
+with Ada.Directories;
 with Ada.Command_Line; use Ada.Command_Line;
 with XE_Defs;          use XE_Defs;
 with XE_Flags;         use XE_Flags;
@@ -81,12 +82,14 @@
       S3 : String := No_Str);
 
    type Sigint_Handler is access procedure;
+   pragma Convention (C, Sigint_Handler);
 
    procedure Install_Int_Handler (Handler : Sigint_Handler);
    pragma Import (C, Install_Int_Handler, "__gnat_install_int_handler");
    --  Called by Gnatmake to install the SIGINT handler below
 
    procedure Sigint_Intercepted;
+   pragma Convention (C, Sigint_Intercepted);
    --  Called when the program is interrupted by Ctrl-C to delete the
    --  temporary mapping files and configuration pragmas files.
 
@@ -501,6 +504,11 @@
    ----------------
 
    procedure Initialize is
+      Command : constant String := Ada.Directories.Base_Name
+        (Ada.Command_Line.Command_Name);
+      GNAT    : constant String :=
+        Command (Command'First .. Command'Last - 4);
+      --  calculate `[target-]gnat` driver name by gnatdist exe name
    begin
       XE_Names.Initialize;
       Set_Space_Increment (3);
@@ -550,7 +558,7 @@
 
       Create_Dir (Stub_Dir_Name);
 
-      GNAT_Driver := Locate ("gnat");
+      GNAT_Driver := Locate (GNAT);
    end Initialize;
 
    ----------
@@ -818,6 +826,7 @@
 
       if Program_Args = Binder
         or else Program_Args = Linker
+        or else Program_Args = Compiler
       then
          Add_Make_Switch (Argv);
          return;
