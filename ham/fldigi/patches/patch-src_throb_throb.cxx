$NetBSD: patch-src_throb_throb.cxx,v 1.1 2012/11/19 23:23:39 joerg Exp $

--- src/throb/throb.cxx.orig	2012-11-19 16:10:27.000000000 +0000
+++ src/throb/throb.cxx
@@ -410,7 +410,6 @@ void throb::decodechar(int tone1, int to
 
 void throb::rx(complex in)
 {
-	complex rxword[num_tones];
 	int i, tone1, tone2, maxtone;
 
 	symbol[symptr] = in;
@@ -418,6 +417,8 @@ void throb::rx(complex in)
 	if (rxcntr > 0.0)
 		return;
 
+	complex *rxword = new complex[num_tones];
+
 // correlate against all tones
 	for (i = 0; i < num_tones; i++)
 		rxword[i] = cmac(rxtone[i], symbol, symptr + 1, rxsymlen);
@@ -445,6 +446,8 @@ void throb::rx(complex in)
 		set_freq(frequency + f / (num_tones - 1));
 	}
 
+	delete[] rxword;
+
 	/* done with this symbol, start over */
 	rxcntr = rxsymlen;
 	waitsync = 1;
