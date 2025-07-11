$NetBSD: patch-Dist_xe__parse.adb,v 1.1 2025/07/11 06:17:38 dkazankov Exp $

Fix some compilation warnings
https://github.com/reznikmm/garlic/commit/b738f20db65add57f817f952a625df73bef0710e

--- Dist/xe_parse.adb.orig	2007-11-26 14:06:30.000000000 +0200
+++ Dist/xe_parse.adb
@@ -973,6 +973,7 @@
       end if;
 
       --  Declare <X> as a formal parameter.
+      pragma Warnings (Off, "modified by call");
 
       Declare_Subprogram_Parameter
         (Parameter_Name,
@@ -1007,6 +1008,7 @@
          Function_Node,
          Para_Type_Sloc,
          Parameter_Node);
+      pragma Warnings (On, "modified by call");
 
       T_Semicolon;
    end P_Function_Declaration;
@@ -1159,7 +1161,8 @@
          --  of the predefined type Partition_Type_Node.
 
          if Partition_Node = Null_Variable or else
-           Get_Variable_Type (Partition_Node) /= Partition_Type_Node then
+           Get_Variable_Type (Partition_Node) /= Partition_Type_Node
+         then
             Write_Conflict_Error (Partition_Sloc, Partition_Name);
          end if;
 
@@ -1952,8 +1955,7 @@
 
             --  If Named, use Formal_Name to return format parameter node.
             when Named =>
-               if Get_Node_Name
-                 (Node_Id (Parameter_Node)) = Formal_Name then
+               if Get_Node_Name (Node_Id (Parameter_Node)) = Formal_Name then
                   return;
                end if;
 
@@ -2128,7 +2130,8 @@
    begin
       Search_Declaration (Variable_Name, Node);
       if Node /= Null_Node  and then
-         not Is_Variable (Node) then
+         not Is_Variable (Node)
+      then
          Node := Null_Node;
       end if;
       Variable_Node := Variable_Id (Node);
