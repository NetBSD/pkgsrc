$NetBSD: patch-3rd__party_boost_process_detail_posix_handles.hpp,v 1.1 2026/01/04 00:26:42 wiz Exp $

--- 3rd_party/boost/process/detail/posix/handles.hpp.orig	2021-09-10 09:36:53.000000000 +0000
+++ 3rd_party/boost/process/detail/posix/handles.hpp
@@ -31,7 +31,7 @@ inline std::vector<native_handle_type> g
     else
         ec.clear();
 
-    auto my_fd = ::dirfd(dir.get());
+    auto my_fd = dirfd(dir.get());
 
     struct ::dirent * ent_p;
 
@@ -115,7 +115,7 @@ struct limit_handles_ : handler_base_ext
             return;
         }
 
-        auto my_fd = ::dirfd(dir);
+        auto my_fd = dirfd(dir);
         struct ::dirent * ent_p;
 
         while ((ent_p = readdir(dir)) != nullptr)
