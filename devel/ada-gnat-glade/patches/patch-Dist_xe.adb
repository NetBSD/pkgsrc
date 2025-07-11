$NetBSD: patch-Dist_xe.adb,v 1.1 2025/07/11 06:17:37 dkazankov Exp $

Fix some compilation warnings
https://github.com/reznikmm/garlic/commit/b738f20db65add57f817f952a625df73bef0710e

--- Dist/xe.adb.orig	2007-11-26 14:06:30.000000000 +0200
+++ Dist/xe.adb
@@ -1171,7 +1171,7 @@
       --  Remove the nodes created in the previous context.
 
       loop
-         exit when Nodes.Last <= Node_Id (Context.Last_Node);
+         exit when Nodes.Last <= Context.Last_Node;
          Nodes.Decrement_Last;
       end loop;
       N_Anonymous_Variable := Context.Anonymous;
