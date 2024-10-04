$NetBSD: patch-libs_process_src_posix_close__handles.cpp,v 1.1 2024/10/04 03:26:54 ryoon Exp $

* NetBSD has no close_range and closefrom.
* dirfd is a macro for NetBSD.

--- libs/process/src/posix/close_handles.cpp.orig	2024-08-07 22:07:40.000000000 +0000
+++ libs/process/src/posix/close_handles.cpp
@@ -17,7 +17,7 @@
 // linux has close_range since 5.19
 
 
-#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__)
 
 // https://www.freebsd.org/cgi/man.cgi?query=close_range&apropos=0&sektion=0&manpath=FreeBSD+13.1-RELEASE+and+Ports&arch=default&format=html
 // https://man.netbsd.org/closefrom.3
@@ -185,7 +185,7 @@ void close_all(const std::vector<int> & 
         return ;
     }
 
-    auto dir_fd = ::dirfd(dir.get());
+    auto dir_fd = dirfd(dir.get());
     if (dir_fd == -1)
     {
         ec = BOOST_PROCESS_V2_NAMESPACE::detail::get_last_error();
@@ -219,4 +219,4 @@ void close_all(const std::vector<int> & 
 
 BOOST_PROCESS_V2_END_NAMESPACE
 
-#endif
\ No newline at end of file
+#endif
