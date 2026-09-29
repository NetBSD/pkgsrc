$NetBSD: patch-common_api_api__handler__common.cpp,v 1.1 2026/09/29 16:11:56 bouyer Exp $

Avoid conflict with major()/minor() macro from sys/types.h.

--- common/api/api_handler_common.cpp.orig	2025-03-15 02:15:24.615413380 +0000
+++ common/api/api_handler_common.cpp
@@ -73,8 +73,8 @@ HANDLER_RESULT<GetVersionResponse> API_H
     reply.mutable_version()->set_full_version( GetBuildVersion().ToStdString() );
 
     std::tuple<int, int, int> version = GetMajorMinorPatchTuple();
-    reply.mutable_version()->set_major( std::get<0>( version ) );
-    reply.mutable_version()->set_minor( std::get<1>( version ) );
+    reply.mutable_version()->set_k_major( std::get<0>( version ) );
+    reply.mutable_version()->set_k_minor( std::get<1>( version ) );
     reply.mutable_version()->set_patch( std::get<2>( version ) );
 
     return reply;
