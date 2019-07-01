$NetBSD: patch-boost_stacktrace_detail_collect__unwind.ipp,v 1.2 2019/07/01 04:00:10 ryoon Exp $

Fix build with gcc 5.4.0 "error: expected id-expression before numeric constant"

--- boost/stacktrace/detail/collect_unwind.ipp.orig	2019-04-09 19:36:33.000000000 +0000
+++ boost/stacktrace/detail/collect_unwind.ipp
@@ -48,7 +48,7 @@ inline _Unwind_Reason_Code unwind_callba
     unwind_state* const state = static_cast<unwind_state*>(arg);
     if (state->frames_to_skip) {
         --state->frames_to_skip;
-        return _Unwind_GetIP(context) ? ::_URC_NO_REASON : ::_URC_END_OF_STACK;
+        return _Unwind_GetIP(context) ? _URC_NO_REASON : _URC_END_OF_STACK;
     }
 
     *state->current =  reinterpret_cast<native_frame_ptr_t>(
@@ -57,9 +57,9 @@ inline _Unwind_Reason_Code unwind_callba
 
     ++state->current;
     if (!*(state->current - 1) || state->current == state->end) {
-        return ::_URC_END_OF_STACK;
+        return _URC_END_OF_STACK;
     }
-    return ::_URC_NO_REASON;
+    return _URC_NO_REASON;
 }
 #endif //!defined(BOOST_STACKTRACE_USE_LIBC_BACKTRACE_FUNCTION)
 
