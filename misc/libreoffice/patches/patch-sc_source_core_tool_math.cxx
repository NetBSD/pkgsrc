$NetBSD: patch-sc_source_core_tool_math.cxx,v 1.5 2024/10/08 05:57:31 ryoon Exp $

The older NetBSD has no math_errhandling support yet.

--- sc/source/core/tool/math.cxx.orig	2021-08-16 19:56:28.000000000 +0000
+++ sc/source/core/tool/math.cxx
@@ -20,7 +20,9 @@ static double err_pow(const double& fVal
 {
     // pow() is expected to set domain error or pole error or range error (or
     // flag them via exceptions) or return NaN or Inf.
+#if defined(MATH_ERREXCEPT)
     assert((math_errhandling & (MATH_ERRNO | MATH_ERREXCEPT)) != 0);
+#endif
     std::feclearexcept(FE_ALL_EXCEPT);
     errno = 0;
     return pow(fVal1, fVal2);
@@ -52,6 +54,7 @@ double power(const double& fVal1, const 
         fPow = err_pow(fVal1, fVal2);
     }
     // The pow() call must had been the most recent call to check errno or exception.
+#if defined(MATH_ERREXCEPT)
     if ((((math_errhandling & MATH_ERRNO) != 0) && (errno == EDOM || errno == ERANGE))
 // emscripten is currently broken by https://github.com/emscripten-core/emscripten/pull/11087
 // While the removal is correct for C99, it's not for C++11 (see http://www.cplusplus.com/reference/cfenv/FE_INEXACT/)
@@ -61,6 +64,9 @@ double power(const double& fVal1, const 
             && std::fetestexcept(FE_INVALID | FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW))
 #endif
         || !std::isfinite(fPow))
+#else /* non MATH_ERREXCEPT */
+    if (!std::isfinite(fPow))
+#endif
     {
         fPow = CreateDoubleError(FormulaError::IllegalFPOperation);
     }
