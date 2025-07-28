$NetBSD: patch-src_gnatprove_configuration.adb,v 1.1 2025/07/28 07:00:55 dkazankov Exp $

Adjust gnatprove to changes in gpr2 API
The new API simplifies the tree load function, and error reporting.
This requires this change to gnatprove.
https://github.com/AdaCore/spark2014/commit/1567db99c5785a722cb7601e406c486b680c1fd7

Fix compilation error
The function Visible_Source already returns a Source object
https://github.com/AdaCore/spark2014/commit/42ee20a76b74120fb78a83b3f0e2647803b469b9

--- src/gnatprove/configuration.adb.orig	2024-01-11 17:55:20.000000000 +0200
+++ src/gnatprove/configuration.adb
@@ -1466,11 +1466,14 @@
             Status : Boolean;
          begin
             Proj_Opt.Add_Switch (Options.P, Project_File);
-            Proj_Opt.Finalize;
-            Status := Proj_Opt.Load_Project (Tree);
+
+            --  Do not display warnings, as those messages will be duplicated
+            --  during the call to gprbuild.
+            GPR2.Project.Tree.Verbosity := GPR2.Project.Tree.Errors;
+
+            Status := Tree.Load (Proj_Opt, Absent_Dir_Error => GPR2.No_Error);
+
             if not Status then
-               GPR2.Log.Output_Messages
-                 (Tree.Log_Messages.all, Information => False);
                Fail ("");
             end if;
 
@@ -1482,8 +1485,13 @@
                declare
                   Msgs : GPR2.Log.Object;
                begin
-                  Tree.Update_Sources (Messages => Msgs);
-                  GPR2.Log.Output_Messages (Msgs, Information => False);
+                  --  When updating the sources we now need both warnings and
+                  --  errors, in particular since duplicated body situation is
+                  --  a warning.
+
+                  GPR2.Project.Tree.Verbosity :=
+                    GPR2.Project.Tree.Warnings_And_Errors;
+                  Tree.Update_Sources (Msgs);
                end;
             end if;
          end;
@@ -2588,8 +2596,7 @@
                   then
                      CU := View_DB.Compilation_Unit (Elt);
                   elsif View_DB.Source_Option > No_Source then
-                     VS :=
-                       View_DB.Visible_Source (GPR2.Simple_Name (Elt)).Source;
+                     VS := View_DB.Visible_Source (GPR2.Simple_Name (Elt));
                      if VS.Is_Defined
                        and then View_DB.Has_Compilation_Unit (VS.Unit.Name)
                      then
