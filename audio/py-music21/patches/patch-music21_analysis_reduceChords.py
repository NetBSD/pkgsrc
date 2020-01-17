$NetBSD: patch-music21_analysis_reduceChords.py,v 1.1 2020/01/17 05:41:44 gutteridge Exp $

Functional fix: there are two Verticality classes with different features; the
one used here has to have the toChord() method called first to prepare it.
Also, isConsonant() is a method, not an attribute.
https://github.com/cuthbertLab/music21/pull/445

--- music21/analysis/reduceChords.py.orig	2019-06-08 20:37:54.000000000 +0000
+++ music21/analysis/reduceChords.py
@@ -651,7 +651,7 @@ class ChordReducer:
             # print(verticality, intervalClassSet, allowableChords, forbiddenChords)
             if allowableChords and intervalClassSet in allowableChords:
                 isConsonant = True
-            if verticality.isConsonant:
+            if verticality.toChord().isConsonant():
                 isConsonant = True
             if forbiddenChords and intervalClassSet in forbiddenChords:
                 isConsonant = False
