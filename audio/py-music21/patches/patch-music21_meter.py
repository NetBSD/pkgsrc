$NetBSD: patch-music21_meter.py,v 1.1 2020/01/17 05:41:44 gutteridge Exp $

Fix a reference so that the test case actually executes.
https://github.com/cuthbertLab/music21/pull/443

--- music21/meter.py.orig	2019-06-08 19:42:53.000000000 +0000
+++ music21/meter.py
@@ -4441,8 +4441,8 @@ class TestExternal(unittest.TestCase):  
         a = stream.Stream()
         for meterStrDenominator in [1, 2, 4, 8, 16, 32]:
             for meterStrNumerator in [2, 3, 4, 5, 6, 7, 9, 11, 12, 13]:
-                ts = music21.meter.TimeSignature('%s/%s' % (meterStrNumerator,
-                                                            meterStrDenominator))
+                ts = TimeSignature('%s/%s' % (meterStrNumerator,
+                                              meterStrDenominator))
                 m = stream.Measure()
                 m.timeSignature = ts
                 a.insert(m.timeSignature.barDuration.quarterLength, m)
