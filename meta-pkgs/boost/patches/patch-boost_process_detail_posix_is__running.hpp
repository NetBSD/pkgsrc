$NetBSD: patch-boost_process_detail_posix_is__running.hpp,v 1.1 2020/09/09 06:38:52 tnn Exp $

Cannot use static asserts on WIFEXITED() & friends because the
internal _W_INT macro uses (void*) which is not allowed in constexprs.

--- boost/process/detail/posix/is_running.hpp.orig	2020-04-22 13:35:49.000000000 +0000
+++ boost/process/detail/posix/is_running.hpp
@@ -17,10 +17,12 @@ namespace boost { namespace process { na
 // This bit arrangement of status codes is not guaranteed by POSIX, but (according to comments in
 // the glibc <bits/waitstatus.h> header) is the same across systems in practice.
 constexpr int still_active = 0x017f;
+#if !defined(__NetBSD__)
 static_assert(WIFSTOPPED(still_active), "Expected still_active to indicate WIFSTOPPED");
 static_assert(!WIFEXITED(still_active), "Expected still_active to not indicate WIFEXITED");
 static_assert(!WIFSIGNALED(still_active), "Expected still_active to not indicate WIFSIGNALED");
 static_assert(!WIFCONTINUED(still_active), "Expected still_active to not indicate WIFCONTINUED");
+#endif
 
 inline bool is_running(int code)
 {
