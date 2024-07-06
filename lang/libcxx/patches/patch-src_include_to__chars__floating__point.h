$NetBSD: patch-src_include_to__chars__floating__point.h,v 1.2 2024/07/06 15:45:07 adam Exp $

#if out some code that doesn't compile with GCC < 11 for now

--- src/include/to_chars_floating_point.h.orig	2024-04-17 00:21:15.000000000 +0000
+++ src/include/to_chars_floating_point.h
@@ -93,6 +93,7 @@ struct _Floating_type_traits<double> {
 
 // ^^^^^^^^^^ DERIVED FROM corecrt_internal_fltintrn.h ^^^^^^^^^^
 
+#if _LIBCPP_STD_VER > 17
 // FUNCTION to_chars (FLOATING-POINT TO STRING)
 template <class _Floating>
 [[nodiscard]] _LIBCPP_HIDE_FROM_ABI
@@ -332,7 +333,9 @@ to_chars_result _Floating_to_chars_hex_p
     // We've already printed '-' if necessary, so uint32_t _Absolute_exponent avoids testing that again.
     return std::to_chars(_First, _Last, _Absolute_exponent);
 }
+#endif
 
+#if _LIBCPP_STD_VER > 17
 template <class _Floating>
 [[nodiscard]] _LIBCPP_HIDE_FROM_ABI
 to_chars_result _Floating_to_chars_hex_shortest(
@@ -459,6 +462,7 @@ to_chars_result _Floating_to_chars_hex_s
     // We've already printed '-' if necessary, so static_cast<uint32_t> avoids testing that again.
     return std::to_chars(_First, _Last, static_cast<uint32_t>(_Unbiased_exponent));
 }
+#endif
 
 // For general precision, we can use lookup tables to avoid performing trial formatting.
 
@@ -831,6 +835,7 @@ struct _General_precision_tables<double>
         0x7FEFFFFFFFFFFFFFu};
 };
 
+#if _LIBCPP_STD_VER > 17
 template <class _Floating>
 [[nodiscard]] _LIBCPP_HIDE_FROM_ABI
 to_chars_result _Floating_to_chars_general_precision(
@@ -983,9 +988,11 @@ to_chars_result _Floating_to_chars_gener
 
     return {_First, errc{}};
 }
+#endif
 
 enum class _Floating_to_chars_overload { _Plain, _Format_only, _Format_precision };
 
+#if _LIBCPP_STD_VER > 17
 template <_Floating_to_chars_overload _Overload, class _Floating>
 [[nodiscard]] _LIBCPP_HIDE_FROM_ABI
 to_chars_result _Floating_to_chars(
@@ -1071,6 +1078,7 @@ to_chars_result _Floating_to_chars(
         }
     }
 }
+#endif
 
 // clang-format on
 
