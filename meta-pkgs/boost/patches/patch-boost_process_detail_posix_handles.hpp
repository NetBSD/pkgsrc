$NetBSD: patch-boost_process_detail_posix_handles.hpp,v 1.2 2020/09/10 07:54:52 tnn Exp $

dirfd(3) on NetBSD is implemented as a macro and cannot use namespace prefix.

--- boost/process/detail/posix/handles.hpp.orig	2020-04-22 13:35:49.000000000 +0000
+++ boost/process/detail/posix/handles.hpp
@@ -31,7 +31,11 @@ inline std::vector<native_handle_type> g
     else
         ec.clear();
 
+#ifdef dirfd
+    auto my_fd = dirfd(dir.get());
+#else
     auto my_fd = ::dirfd(dir.get());
+#endif
 
     struct ::dirent * ent_p;
 
@@ -115,7 +119,11 @@ struct limit_handles_ : handler_base_ext
             return;
         }
 
+#ifdef dirfd
+        auto my_fd = dirfd(dir);
+#else
         auto my_fd = ::dirfd(dir);
+#endif
         struct ::dirent * ent_p;
 
         while ((ent_p = readdir(dir)) != nullptr)
