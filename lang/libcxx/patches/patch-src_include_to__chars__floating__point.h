$NetBSD: patch-src_include_to__chars__floating__point.h,v 1.1 2022/08/13 09:38:09 tnn Exp $

#if out some code that doesn't compile with GCC < 11 for now

--- src/include/to_chars_floating_point.h.orig	2022-06-22 16:46:24.000000000 +0000
+++ src/include/to_chars_floating_point.h
@@ -90,6 +90,7 @@ struct _Floating_type_traits<double> {
 
 // ^^^^^^^^^^ DERIVED FROM corecrt_internal_fltintrn.h ^^^^^^^^^^
 
+#if _LIBCPP_STD_VER > 17
 // FUNCTION to_chars (FLOATING-POINT TO STRING)
 template <class _Floating>
 [[nodiscard]] _LIBCPP_HIDE_FROM_ABI
@@ -329,7 +330,9 @@ to_chars_result _Floating_to_chars_hex_p
     // We've already printed '-' if necessary, so uint32_t _Absolute_exponent avoids testing that again.
     return _VSTD::to_chars(_First, _Last, _Absolute_exponent);
 }
+#endif
 
+#if _LIBCPP_STD_VER > 17
 template <class _Floating>
 [[nodiscard]] _LIBCPP_HIDE_FROM_ABI
 to_chars_result _Floating_to_chars_hex_shortest(
@@ -456,6 +459,7 @@ to_chars_result _Floating_to_chars_hex_s
     // We've already printed '-' if necessary, so static_cast<uint32_t> avoids testing that again.
     return _VSTD::to_chars(_First, _Last, static_cast<uint32_t>(_Unbiased_exponent));
 }
+#endif
 
 // For general precision, we can use lookup tables to avoid performing trial formatting.
 
@@ -828,6 +832,7 @@ struct _General_precision_tables<double>
         0x7FEFFFFFFFFFFFFFu};
 };
 
+#if _LIBCPP_STD_VER > 17
 template <class _Floating>
 [[nodiscard]] _LIBCPP_HIDE_FROM_ABI
 to_chars_result _Floating_to_chars_general_precision(
@@ -980,9 +985,11 @@ to_chars_result _Floating_to_chars_gener
 
     return {_First, errc{}};
 }
+#endif
 
 enum class _Floating_to_chars_overload { _Plain, _Format_only, _Format_precision };
 
+#if _LIBCPP_STD_VER > 17
 template <_Floating_to_chars_overload _Overload, class _Floating>
 [[nodiscard]] _LIBCPP_HIDE_FROM_ABI
 to_chars_result _Floating_to_chars(
@@ -1068,6 +1075,7 @@ to_chars_result _Floating_to_chars(
         }
     }
 }
+#endif
 
 // clang-format on
 
