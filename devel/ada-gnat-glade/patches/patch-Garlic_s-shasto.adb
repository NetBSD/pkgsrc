$NetBSD: patch-Garlic_s-shasto.adb,v 1.1 2025/07/11 06:17:39 dkazankov Exp $

Implementation of Shared_Var_Procs specs

--- Garlic/s-shasto.adb.orig	2007-11-26 15:35:25.000000000 +0200
+++ Garlic/s-shasto.adb
@@ -31,17 +31,24 @@
 --                                                                          --
 ------------------------------------------------------------------------------
 
+with Ada.Streams.Stream_IO;
+
 with System.Garlic.Exceptions; use System.Garlic.Exceptions;
 with System.Garlic.Storages;   use System.Garlic.Storages;
 
 package body System.Shared_Storage is
 
+   use Ada.Streams.Stream_IO;
+
+   procedure Shared_Var_Close (Var : in out Stream_Access);
+   function Shared_Var_ROpen (Var : String) return Stream_Access;
+   function Shared_Var_WOpen (Var : String) return Stream_Access;
+
    ----------------------
    -- Shared_Var_Close --
    ----------------------
 
-   procedure Shared_Var_Close (Var : in out SIO.Stream_Access)
-   is
+   procedure Shared_Var_Close (Var : in out Stream_Access) is
       VS : Shared_Data_Access;
       pragma Warnings (Off, Var);
    begin
@@ -53,8 +60,7 @@
    -- Shared_Var_Lock --
    ---------------------
 
-   procedure Shared_Var_Lock (Var : String)
-   is
+   procedure Shared_Var_Lock (Var : String) is
       VS : Shared_Data_Access;
       Ok : Boolean;
       E  : aliased Error_Type;
@@ -71,8 +77,7 @@
    -- Shared_Var_ROpen --
    ----------------------
 
-   function Shared_Var_ROpen (Var : String) return SIO.Stream_Access
-   is
+   function Shared_Var_ROpen (Var : String) return Stream_Access is
       VS : Shared_Data_Access;
       Ok : Boolean;
       E  : aliased Error_Type;
@@ -84,7 +89,7 @@
       end if;
       Initiate_Request (VS, Read, Ok);
       if Ok then
-         return SIO.Stream_Access (VS);
+         return Stream_Access (VS);
       else
          return null;
       end if;
@@ -94,8 +99,7 @@
    -- Shared_Var_Unlock --
    -----------------------
 
-   procedure Shared_Var_Unlock (Var : String)
-   is
+   procedure Shared_Var_Unlock (Var : String) is
       VS : Shared_Data_Access;
       E  : aliased Error_Type;
 
@@ -111,8 +115,7 @@
    -- Shared_Var_WOpen --
    ----------------------
 
-   function Shared_Var_WOpen (Var : String) return SIO.Stream_Access
-   is
+   function Shared_Var_WOpen (Var : String) return Stream_Access is
       VS : Shared_Data_Access;
       Ok : Boolean;
       E  : aliased Error_Type;
@@ -123,7 +126,46 @@
          Raise_Communication_Error (Content (E'Access));
       end if;
       Initiate_Request (VS, Write, Ok);
-      return SIO.Stream_Access (VS);
+      return Stream_Access (VS);
    end Shared_Var_WOpen;
 
+   ----------------------
+   -- Shared_Var_Procs --
+   ----------------------
+
+   package body Shared_Var_Procs is
+
+      --  XXX for instance, we use stream attributes to
+      --  assign variable V of limited type Typ.
+
+      ----------
+      -- Read --
+      ----------
+
+      procedure Read is
+         S : Stream_Access := Shared_Var_ROpen (Full_Name);
+
+      begin
+         if S /= null then
+            Typ'Read  (S, V);
+            Shared_Var_Close (S);
+         end if;
+      end Read;
+
+      -----------
+      -- Write --
+      -----------
+
+      procedure Write is
+         S : Stream_Access := Shared_Var_WOpen (Full_Name);
+
+      begin
+         if S /= null then
+            Typ'Write  (S, V);
+            Shared_Var_Close (S);
+         end if;
+      end Write;
+
+   end Shared_Var_Procs;
+
 end System.Shared_Storage;
