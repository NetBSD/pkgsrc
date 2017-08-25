$NetBSD: patch-boost_stacktrace_detail_collect__unwind.ipp,v 1.1 2017/08/25 21:49:43 prlw1 Exp $

Fix build with gcc 5.4.0 "error: expected id-expression before numeric constant"

--- boost/stacktrace/detail/collect_unwind.ipp.orig	2017-08-25 18:22:01.228205991 +0000
+++ boost/stacktrace/detail/collect_unwind.ipp
@@ -31,7 +31,7 @@ inline _Unwind_Reason_Code unwind_callba
     unwind_state* const state = static_cast<unwind_state*>(arg);
     if (state->frames_to_skip) {
         --state->frames_to_skip;
-        return _Unwind_GetIP(context) ? ::_URC_NO_REASON : ::_URC_END_OF_STACK;
+        return _Unwind_GetIP(context) ? _URC_NO_REASON : _URC_END_OF_STACK;
     }
 
     *state->current =  reinterpret_cast<native_frame_ptr_t>(
@@ -40,9 +40,9 @@ inline _Unwind_Reason_Code unwind_callba
 
     ++state->current;
     if (!*(state->current - 1) || state->current == state->end) {
-        return ::_URC_END_OF_STACK;
+        return _URC_END_OF_STACK;
     }
-    return ::_URC_NO_REASON;
+    return _URC_NO_REASON;
 }
 
 std::size_t this_thread_frames::collect(native_frame_ptr_t* out_frames, std::size_t max_frames_count, std::size_t skip) BOOST_NOEXCEPT {
