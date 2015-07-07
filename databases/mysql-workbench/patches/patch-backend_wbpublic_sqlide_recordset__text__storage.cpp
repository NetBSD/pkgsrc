$NetBSD: patch-backend_wbpublic_sqlide_recordset__text__storage.cpp,v 1.1 2015/07/07 11:45:52 joerg Exp $

--- backend/wbpublic/sqlide/recordset_text_storage.cpp.orig	2015-06-28 17:59:17.000000000 +0000
+++ backend/wbpublic/sqlide/recordset_text_storage.cpp
@@ -162,7 +162,7 @@ void Recordset_text_storage::do_serializ
       if (!pre_tpl)
         g_warning("Failed to open template file: `%s`", pre_tpl_path.c_str()); 
       else
-        pre_tpl->ReloadIfChanged();
+        pre_tpl->ReloadAllIfChanged();
     }      
     if (g_file_test((name+".post.tpl").c_str(), G_FILE_TEST_EXISTS))
     {
@@ -171,7 +171,7 @@ void Recordset_text_storage::do_serializ
       if (!post_tpl)
         g_warning("Failed to open template file: `%s`", post_tpl_path.c_str());
       else
-        post_tpl->ReloadIfChanged();
+        post_tpl->ReloadAllIfChanged();
     }
   }    
   
@@ -180,7 +180,7 @@ void Recordset_text_storage::do_serializ
       throw std::runtime_error(strfmt("Failed to open output file: `%s`", _file_path.c_str()));
   }
 
-  tpl->ReloadIfChanged();
+  tpl->ReloadAllIfChanged();
 
   std::auto_ptr<TemplateDictionary> dict(new TemplateDictionary("/"));
   BOOST_FOREACH (const Parameters::value_type &param, _parameters)
