$NetBSD: patch-plugin_x_src_prepare__param__handler.cc,v 1.1 2025/10/22 07:21:48 jnemeth Exp $

--- plugin/x/src/prepare_param_handler.cc.orig	2025-10-20 03:36:31.577775897 +0000
+++ plugin/x/src/prepare_param_handler.cc
@@ -28,6 +28,7 @@
 #include <my_byteorder.h>
 
 #include <string>
+#include <string_view>
 
 #include "plugin/x/src/ngs/mysqlx/getter_any.h"
 #include "plugin/x/src/xpl_error.h"
@@ -147,8 +148,8 @@ ngs::Error_code Prepare_param_handler::p
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
