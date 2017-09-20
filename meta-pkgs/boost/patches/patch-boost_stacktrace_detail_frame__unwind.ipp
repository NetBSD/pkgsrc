$NetBSD: patch-boost_stacktrace_detail_frame__unwind.ipp,v 1.1 2017/09/20 14:33:25 jperkin Exp $

Fix build on OS where dladdr() takes a void *.

--- boost/stacktrace/detail/frame_unwind.ipp.orig	2017-09-20 14:09:31.984874879 +0000
+++ boost/stacktrace/detail/frame_unwind.ipp
@@ -84,7 +84,7 @@ std::string to_string(const frame* frame
 std::string frame::name() const {
 #if !defined(BOOST_WINDOWS) && !defined(__CYGWIN__)
     ::Dl_info dli;
-    const bool dl_ok = !!::dladdr(addr_, &dli);
+    const bool dl_ok = !!::dladdr(const_cast<void*>(addr_), &dli);
     if (dl_ok && dli.dli_sname) {
         return boost::core::demangle(dli.dli_sname);
     }
