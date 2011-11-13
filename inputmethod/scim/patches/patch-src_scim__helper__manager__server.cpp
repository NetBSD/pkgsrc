$NetBSD: patch-src_scim__helper__manager__server.cpp,v 1.1 2011/11/13 07:52:02 obache Exp $

* Variable Length Arrays with non-POD types are a GCC extension.

--- src/scim_helper_manager_server.cpp.orig	2008-10-19 04:48:33.000000000 +0000
+++ src/scim_helper_manager_server.cpp
@@ -95,10 +95,10 @@ void load_helper_modules (void)
     //      so I added a workaround: have an array of modules and unload them all together in the end only.
     //      TODO Need to figure out what's going on with this issue.
 
-    HelperModule module[mod_list.size ()];
-
     if (mod_list.size ()) {
 
+        HelperModule *module = new HelperModule[mod_list.size ()];
+
         for (size_t i = 0; i < mod_list.size (); ++i) {
 
             SCIM_DEBUG_MAIN (2) << " Load module: " << mod_list [i] << "\n";
@@ -120,6 +120,7 @@ void load_helper_modules (void)
         for (size_t i = 0; i < mod_list.size (); ++i) {
             module[i].unload ();
         }
+        delete[] module;
     }
 }
 
