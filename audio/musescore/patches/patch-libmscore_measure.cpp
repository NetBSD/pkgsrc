$NetBSD: patch-libmscore_measure.cpp,v 1.1 2021/01/25 02:42:44 gutteridge Exp $

Upstream fix for bug #315529: crash on load of score with repeat
https://github.com/musescore/MuseScore/commit/39b6a58b0c028e16d5a4e69d8d99aa9f069bfe11

--- libmscore/measure.cpp.orig	2021-01-15 12:36:02.000000000 +0000
+++ libmscore/measure.cpp
@@ -2897,7 +2897,7 @@ bool Measure::isCutawayClef(int staffIdx
             etrack = strack + VOICES;
             }
       // find segment before EndBarLine
-      Segment* s;
+      Segment* s = nullptr;
       for (Segment* ls = last(); ls; ls = ls->prev()) {
             if (ls->segmentType() ==  SegmentType::EndBarLine) {
                   s = ls->prev();
