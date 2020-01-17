$NetBSD: patch-music21_humdrum_spineParser.py,v 1.1 2020/01/17 05:41:44 gutteridge Exp $

parse() must be called first to generate a stream.
https://github.com/cuthbertLab/music21/pull/446

--- music21/humdrum/spineParser.py.orig	2019-06-08 19:49:52.000000000 +0000
+++ music21/humdrum/spineParser.py
@@ -2894,6 +2894,7 @@ class TestExternal(unittest.TestCase):  
 
     def testShowSousa(self):
         hf1 = HumdrumDataCollection(testFiles.sousaStars)
+        hf1.parse()
         hf1.stream.show()
 
 
