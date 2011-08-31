$NetBSD: patch-akode-lib-volumefilter.cpp,v 1.1 2011/08/31 14:43:43 joerg Exp $

--- akode/lib/volumefilter.cpp.orig	2011-08-30 13:56:43.000000000 +0000
+++ akode/lib/volumefilter.cpp
@@ -29,7 +29,7 @@ namespace aKode {
 VolumeFilter::VolumeFilter() : m_volume(0) {}
 
 // T is the input/output type, S is the fast arithmetics type, Arithm is a division definition
-template<typename T, typename S, template<typename S> class Arithm>
+template<typename T, typename S, template<typename U> class Arithm>
 static bool _doFrame(AudioFrame* in, AudioFrame* out, int volume)
 {
     T** indata = (T**)in->data;
