$NetBSD: patch-src_sound_ResampleHQ.cc,v 1.1 2013/09/20 23:04:59 joerg Exp $

--- src/sound/ResampleHQ.cc.orig	2013-09-20 13:34:58.000000000 +0000
+++ src/sound/ResampleHQ.cc
@@ -205,7 +205,7 @@ ResampleHQ<CHANNELS>::~ResampleHQ()
 
 template <unsigned CHANNELS>
 void ResampleHQ<CHANNELS>::calcOutput(
-	float pos, int* __restrict output) __restrict
+	float pos, int* output)
 {
 	assert((filterLen & 3) == 0);
 	int t = int(pos * TAB_LEN + 0.5f) % TAB_LEN;
@@ -447,7 +447,7 @@ void ResampleHQ<CHANNELS>::prepareData(u
 
 template <unsigned CHANNELS>
 bool ResampleHQ<CHANNELS>::generateOutput(
-	int* __restrict dataOut, unsigned hostNum, EmuTime::param time) __restrict
+	int* dataOut, unsigned hostNum, EmuTime::param time)
 {
 	unsigned emuNum = emuClock.getTicksTill(time);
 	if (emuNum > 0) {
