$NetBSD: patch-sc_source_core_tool_math.cxx,v 1.2 2020/08/11 16:07:39 ryoon Exp $

NetBSD has no math_errhandling support yet.

--- sc/source/core/tool/math.cxx.orig	2020-07-29 19:29:17.000000000 +0000
+++ sc/source/core/tool/math.cxx
@@ -20,7 +20,9 @@ static double err_pow( const double& fVa
 {
     // pow() is expected to set domain error or pole error or range error (or
     // flag them via exceptions) or return NaN or Inf.
+#if !defined(__NetBSD__)
     assert((math_errhandling & (MATH_ERRNO | MATH_ERREXCEPT)) != 0);
+#endif
     std::feclearexcept(FE_ALL_EXCEPT);
     errno = 0;
     return pow( fVal1, fVal2);
@@ -52,10 +54,15 @@ double power( const double& fVal1, const
         fPow = err_pow( fVal1, fVal2);
     }
     // The pow() call must had been the most recent call to check errno or exception.
+#if defined(__NetBSD__)
+    if ((errno == EDOM || errno == ERANGE)
+            || !rtl::math::isFinite(fPow))
+#else
     if ((((math_errhandling & MATH_ERRNO) != 0) && (errno == EDOM || errno == ERANGE))
             || (((math_errhandling & MATH_ERREXCEPT) != 0)
                 && std::fetestexcept( FE_INVALID | FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW))
             || !std::isfinite(fPow))
+#endif
     {
         fPow = CreateDoubleError( FormulaError::IllegalFPOperation);
     }
