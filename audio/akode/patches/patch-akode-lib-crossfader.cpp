$NetBSD: patch-akode-lib-crossfader.cpp,v 1.1 2011/08/31 14:43:43 joerg Exp $

--- akode/lib/crossfader.cpp.orig	2011-08-30 13:55:31.000000000 +0000
+++ akode/lib/crossfader.cpp
@@ -27,7 +27,7 @@ namespace aKode {
 CrossFader::CrossFader(unsigned int time) : time(time),pos(0) {}
 
 // T is the input/output type, S is the fast arithmetics type, Div is a division method
-template<typename T, typename S, template<typename S> class Arithm>
+template<typename T, typename S, template<typename U> class Arithm>
 static bool _doFrame(AudioFrame* in, int& pos, AudioFrame* frame)
 {
     T** indata1 = (T**)in->data;
@@ -66,7 +66,7 @@ static bool _doFrame(AudioFrame* in, int
 }
 
 // T is the input/output type, S is the fast arithmetics type, Arithm defines devisions
-template<typename T, typename S, template<typename S> class Arithm>
+template<typename T, typename S, template<typename U> class Arithm>
 static bool _readFrame(AudioFrame* in, int& pos, AudioFrame* frame)
 {
     T** indata = (T**)frame->data;
