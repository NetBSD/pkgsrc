$NetBSD: patch-Source_pysvn__client__cmd__checkin.cpp,v 1.1 2012/11/16 00:43:11 joerg Exp $

--- Source/pysvn_client_cmd_checkin.cpp.orig	2012-11-15 14:44:17.000000000 +0000
+++ Source/pysvn_client_cmd_checkin.cpp
@@ -208,7 +208,7 @@ Py::Object pysvn_client::cmd_checkout( c
 
         PythonAllowThreads permission( m_context );
 
-        svn_revnum_t revnum = 0;
+        revnum = 0;
 
 #if defined( PYSVN_HAS_CLIENT_CHECKOUT3 )
         svn_error_t *error = svn_client_checkout3
