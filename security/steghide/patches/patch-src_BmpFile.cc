$NetBSD: patch-src_BmpFile.cc,v 1.3 2022/05/05 12:20:34 nia Exp $

avoid ambiguous math functions

--- src/BmpFile.cc.orig	2003-09-28 15:30:30.000000000 +0000
+++ src/BmpFile.cc
@@ -36,6 +36,8 @@
 #include "common.h"
 #include "error.h"
 
+using std::sqrt;
+
 BmpFile::BmpFile (BinaryIO *io)
 	: CvrStgFile()
 {
@@ -214,10 +216,10 @@ std::vector<SampleValueAdjacencyList*> B
 		// create reservoir - for every i reservoir[i] contains the sample values that are neighbourss of
 		// the sample value with label i and have a lower label (and have already been found)
 		// This is necessary to use collapsing trees together with bucket sort (without huge increase in memory usage)
-		std::vector<BmpRGBSampleValue*> reservoir[svs.size()] ;
+		std::vector< std::vector<BmpRGBSampleValue*> > reservoir(svs.size()) ;
 
 		// neighbours sorted by distance (for the current source sample value)
-		std::vector<BmpRGBSampleValue*> neighbours_byd[r + 1] ;
+		std::vector< std::vector<BmpRGBSampleValue*> > neighbours_byd(r + 1) ;
 
 		for (std::vector<SampleValue*>::const_iterator srcsvit = svs.begin() ; srcsvit != svs.end() ; srcsvit++) {
 			BmpRGBSampleValue* srcsv = (BmpRGBSampleValue*) (*srcsvit) ;
