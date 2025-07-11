$NetBSD: patch-Garlic_s-parint.adb,v 1.1 2025/07/11 06:17:38 dkazankov Exp $

Fix compilation error for caller stubs
https://github.com/reznikmm/garlic/commit/97a0ea7e59e509d1328dc6287c432861a9044561
Fix some compilation warnings
https://github.com/reznikmm/garlic/commit/b738f20db65add57f817f952a625df73bef0710e

--- Garlic/s-parint.adb.orig	2007-11-26 15:10:13.000000000 +0200
+++ Garlic/s-parint.adb
@@ -562,6 +562,7 @@
 
       Name : String := RCI_Name;
       Unit : Unit_Id;
+      Initialized : Boolean := False;
 
       -----------------------------
       -- Get_Active_Partition_ID --
@@ -571,6 +572,11 @@
          Partition : Partition_ID;
          Error     : aliased Error_Type;
       begin
+         if not Initialized then
+            Initialized := True;
+            To_Lower (Name);
+            Unit := Get_Unit_Id (Name);
+         end if;
          Get_Partition (Unit, Partition, Error);
          if Found (Error) then
             Raise_Communication_Error (Error'Access);
@@ -586,6 +592,11 @@
          Receiver : Unsigned_64;
          Error    : aliased Error_Type;
       begin
+         if not Initialized then
+            Initialized := True;
+            To_Lower (Name);
+            Unit := Get_Unit_Id (Name);
+         end if;
          Get_Receiver (Unit, Receiver, Error);
          if Found (Error) then
             Raise_Communication_Error (Error'Access);
@@ -593,9 +604,6 @@
          return Receiver;
       end Get_RCI_Package_Receiver;
 
-   begin
-      To_Lower (Name);
-      Unit := Get_Unit_Id (Name);
    end RCI_Locator;
 
    ---------
@@ -622,7 +630,8 @@
       while Caller /= null loop
          D ("Check " & Caller.Name.all & " version consistency");
          if Different (Caller.Version.all,
-                       Get_Unit_Version (Caller.Name.all, Caller.RCI)) then
+                       Get_Unit_Version (Caller.Name.all, Caller.RCI))
+         then
 
             --  If not boot partition, then terminate without waiting for
             --  boot partition request.
