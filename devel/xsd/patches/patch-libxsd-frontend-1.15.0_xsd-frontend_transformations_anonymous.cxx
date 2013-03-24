$NetBSD: patch-libxsd-frontend-1.15.0_xsd-frontend_transformations_anonymous.cxx,v 1.1 2013/03/24 16:58:29 joerg Exp $

--- libxsd-frontend-1.15.0/xsd-frontend/transformations/anonymous.cxx.orig	2013-03-23 19:45:17.000000000 +0000
+++ libxsd-frontend-1.15.0/xsd-frontend/transformations/anonymous.cxx
@@ -270,14 +270,7 @@ namespace XSDFrontend
               // Try to use the portable representation of the path. If that
               // fails, fall back to the native representation.
               //
-              try
-              {
-                file_str = file.string ();
-              }
-              catch (SemanticGraph::InvalidPath const&)
-              {
-                file_str = file.native_file_string ();
-              }
+              file_str = file.string ();
             }
 
             String name (
@@ -354,14 +347,7 @@ namespace XSDFrontend
               // Try to use the portable representation of the path. If that
               // fails, fall back to the native representation.
               //
-              try
-              {
-                file_str = file.string ();
-              }
-              catch (SemanticGraph::InvalidPath const&)
-              {
-                file_str = file.native_file_string ();
-              }
+              file_str = file.string ();
             }
 
             String name (
@@ -555,14 +541,7 @@ namespace XSDFrontend
           // Try to use the portable representation of the path. If that
           // fails, fall back to the native representation.
           //
-          try
-          {
-            file_str = file.string ();
-          }
-          catch (SemanticGraph::InvalidPath const&)
-          {
-            file_str = file.native_file_string ();
-          }
+          file_str = file.string ();
         }
 
         String name (
