$NetBSD: patch-boost_dll_detail_posix_program__location__impl.hpp,v 1.2 2025/10/21 07:53:59 wiz Exp $

Fix build error in this file.
https://github.com/boostorg/dll/issues/106

--- boost/dll/detail/posix/program_location_impl.hpp.orig	2025-10-21 07:45:26.595305483 +0000
+++ boost/dll/detail/posix/program_location_impl.hpp
@@ -100,7 +100,10 @@ namespace boost { namespace dll { namesp
 
 namespace boost { namespace dll { namespace detail {
     inline boost::dll::fs::path program_location_impl(std::error_code &ec) {
-        return boost::dll::fs::read_symlink("/proc/curproc/exe", ec);
+        boost::dll::fs::error_code fs_errc;
+        auto result = boost::dll::fs::read_symlink("/proc/curproc/exe", fs_errc);
+        ec = fs_errc;
+        return result;
     }
 }}} // namespace boost::dll::detail
 
