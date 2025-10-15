$NetBSD: patch-plugin_x_src_prepare__param__handler.cc,v 1.1 2025/10/15 03:52:37 jnemeth Exp $

--- plugin/x/src/prepare_param_handler.cc.orig	2025-09-26 12:59:25.775536085 +0000
+++ plugin/x/src/prepare_param_handler.cc
@@ -147,8 +147,8 @@ ngs::Error_code Prepare_param_handler::p
                         "' and of type '%s' is not supported for binding"
                         " to prepared statement",
                         ph.m_id,
-                        arg.has_scalar() ? arg.scalar().GetTypeName().c_str()
-                                         : arg.GetTypeName().c_str());
+                        arg.has_scalar() ? std::string(arg.scalar().GetTypeName()).c_str()
+                                         : std::string(arg.GetTypeName()).c_str());
     }
   }
   return ngs::Success();
