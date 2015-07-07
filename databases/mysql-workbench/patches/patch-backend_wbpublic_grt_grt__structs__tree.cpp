$NetBSD: patch-backend_wbpublic_grt_grt__structs__tree.cpp,v 1.1 2015/07/07 11:45:52 joerg Exp $

--- backend/wbpublic/grt/grt_structs_tree.cpp.orig	2015-06-28 17:50:16.000000000 +0000
+++ backend/wbpublic/grt/grt_structs_tree.cpp
@@ -140,7 +140,7 @@ std::string StructsTreeBE::get_field_des
   Node *n= get_node_for_id(node);
   
   if (n == NULL)
-    return false;
+    return "";
 
   switch (n->type)
   {
