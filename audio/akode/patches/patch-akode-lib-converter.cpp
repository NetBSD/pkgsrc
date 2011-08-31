$NetBSD: patch-akode-lib-converter.cpp,v 1.1 2011/08/31 14:43:43 joerg Exp $

--- akode/lib/converter.cpp.orig	2011-08-30 13:57:17.000000000 +0000
+++ akode/lib/converter.cpp
@@ -26,7 +26,7 @@ namespace aKode {
 
 Converter::Converter(int sample_width) : m_sample_width(sample_width) {}
 
-template<typename T, typename S, template<typename T> class ArithmT, template<typename S> class ArithmS>
+template<typename T, typename S, template<typename U> class ArithmT, template<typename U> class ArithmS>
 static bool __doFrameFP(AudioFrame* in, AudioFrame* out, int sample_width)
 {
     AudioConfiguration config = *in;
