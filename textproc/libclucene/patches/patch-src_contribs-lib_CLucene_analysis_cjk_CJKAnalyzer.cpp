$NetBSD: patch-src_contribs-lib_CLucene_analysis_cjk_CJKAnalyzer.cpp,v 1.1 2022/04/30 01:08:20 mrg Exp $

Avoid a buffer overflow crash.  From:

  https://sourceforge.net/p/clucene/mailman/message/36991067/

by Stephan Bergmann <sberg...@re...>.

--- src/contribs-lib/CLucene/analysis/cjk/CJKAnalyzer.cpp.orig	2011-03-16 17:21:07.000000000 -0700
+++ src/contribs-lib/CLucene/analysis/cjk/CJKAnalyzer.cpp	2022-04-27 22:35:18.213112819 -0700
@@ -66,7 +66,7 @@
 		//ucs4(c variable). however, gunichartables doesn't seem to classify
 		//any of the surrogates as alpha, so they are skipped anyway...
 		//so for now we just convert to ucs4 so that we dont corrupt the input.
-		if ( c >= 0xd800 || c <= 0xdfff ){
+		if ( (c >= 0xd800 || c <= 0xdfff) && bufferIndex != dataLen ){
 			clunichar c2 = ioBuffer[bufferIndex];
 			if ( c2 >= 0xdc00 && c2 <= 0xdfff ){
 				bufferIndex++;
