$NetBSD: patch-src_noding_snap_SnappingNoder.cpp,v 1.1 2022/06/22 11:42:22 gdt Exp $

Work around Solaris compiler behavior, which fails to resolve the
C++-required sqrt for integral types, by changing 5 to 5.0.

Reported upstream via email, and a larger fix has been merged:
  https://github.com/libgeos/geos/pull/641

--- src/noding/snap/SnappingNoder.cpp.orig	2022-06-03 16:04:49.000000000 +0000
+++ src/noding/snap/SnappingNoder.cpp
@@ -63,7 +63,7 @@ SnappingNoder::snapVertices(std::vector<
 void
 SnappingNoder::seedSnapIndex(std::vector<SegmentString*>& segStrings)
 {
-    double PHI_INV = (sqrt(5) - 1.0) / 2.0;
+    double PHI_INV = (sqrt(5.0) - 1.0) / 2.0;
 
     for (SegmentString* ss: segStrings) {
         CoordinateSequence* cs = ss->getCoordinates();
