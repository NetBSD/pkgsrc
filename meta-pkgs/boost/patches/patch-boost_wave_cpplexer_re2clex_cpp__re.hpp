$NetBSD: patch-boost_wave_cpplexer_re2clex_cpp__re.hpp,v 1.1 2018/05/06 18:46:09 minskim Exp $

Avoid using wrong T_DIVIDE on BSDs.

https://github.com/boostorg/wave/commit/0e25913e

--- boost/wave/cpplexer/re2clex/cpp_re.hpp.orig	2018-04-11 13:49:09.000000000 +0000
+++ boost/wave/cpplexer/re2clex/cpp_re.hpp
@@ -373,6 +373,9 @@ boost::wave::token_id scan(Scanner<Itera
     string_type   rawstringdelim;         // for use with C++11 raw string literals
 
 // include the correct Re2C token definition rules
+#if (defined (__FreeBSD__) || defined (__DragonFly__) || defined (__OpenBSD__)) && defined (T_DIVIDE)
+#undef T_DIVIDE
+#endif
 #if BOOST_WAVE_USE_STRICT_LEXER != 0
 #include "strict_cpp_re.inc"
 #else
