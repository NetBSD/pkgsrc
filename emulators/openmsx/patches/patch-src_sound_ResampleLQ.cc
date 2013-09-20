$NetBSD: patch-src_sound_ResampleLQ.cc,v 1.1 2013/09/20 23:04:59 joerg Exp $

--- src/sound/ResampleLQ.cc.orig	2013-09-20 13:37:42.000000000 +0000
+++ src/sound/ResampleLQ.cc
@@ -89,7 +89,7 @@ ResampleLQUp<CHANNELS>::ResampleLQUp(
 
 template <unsigned CHANNELS>
 bool ResampleLQUp<CHANNELS>::generateOutput(
-	int* __restrict dataOut, unsigned hostNum, EmuTime::param time) __restrict
+	int* dataOut, unsigned hostNum, EmuTime::param time)
 {
 	EmuTime host1 = this->hostClock.getFastAdd(1);
 	assert(host1 > this->emuClock.getTime());
@@ -129,7 +129,7 @@ ResampleLQDown<CHANNELS>::ResampleLQDown
 
 template <unsigned CHANNELS>
 bool ResampleLQDown<CHANNELS>::generateOutput(
-	int* __restrict dataOut, unsigned hostNum, EmuTime::param time) __restrict
+	int* dataOut, unsigned hostNum, EmuTime::param time)
 {
 	EmuTime host1 = this->hostClock.getFastAdd(1);
 	assert(host1 > this->emuClock.getTime());
