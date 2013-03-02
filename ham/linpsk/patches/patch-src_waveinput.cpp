$NetBSD: patch-src_waveinput.cpp,v 1.1 2013/03/02 18:06:22 joerg Exp $

--- src/waveinput.cpp.orig	2013-02-28 22:14:51.000000000 +0000
+++ src/waveinput.cpp
@@ -19,7 +19,7 @@
 
 extern Parameter settings;
 
-WaveInput::WaveInput(int ptt = -1): Input(ptt)
+WaveInput::WaveInput(int ptt): Input(ptt)
 {
  EightBits=false;
 }
