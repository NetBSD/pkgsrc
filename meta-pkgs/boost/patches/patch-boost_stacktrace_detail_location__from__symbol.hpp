$NetBSD: patch-boost_stacktrace_detail_location__from__symbol.hpp,v 1.1 2017/09/20 14:33:25 jperkin Exp $

Fix build on OS where dladdr() takes a void *.

--- boost/stacktrace/detail/location_from_symbol.hpp.orig	2017-09-20 14:09:31.984783070 +0000
+++ boost/stacktrace/detail/location_from_symbol.hpp
@@ -28,7 +28,7 @@ public:
     explicit location_from_symbol(const void* addr) BOOST_NOEXCEPT
         : dli_()
     {
-        if (!::dladdr(addr, &dli_)) {
+        if (!::dladdr(const_cast<void*>(addr), &dli_)) {
             dli_.dli_fname = 0;
         }
     }
