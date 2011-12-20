$NetBSD: patch-src_Wrappers_Encoder_LZEncoder.cpp,v 1.1 2011/12/20 13:42:47 wiz Exp $

Add missing header.

--- src/Wrappers/Encoder/LZEncoder.cpp.orig	2006-08-20 20:41:04.000000000 +0000
+++ src/Wrappers/Encoder/LZEncoder.cpp
@@ -32,6 +32,7 @@
 // Problems: dna@mit.edu
 
 #include "LZEncoder.h"
+#include <stdlib.h>
 
 LZEncoder::LZEncoder(Operator* dataSrc_, int colIndex_, int numIntsPerPage_) : Encoder(dataSrc_, colIndex_)
 {
