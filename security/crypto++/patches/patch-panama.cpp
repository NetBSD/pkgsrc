$NetBSD: patch-panama.cpp,v 1.1 2012/04/17 17:46:31 joerg Exp $

--- panama.cpp.orig	2012-04-17 15:42:03.000000000 +0000
+++ panama.cpp
@@ -420,7 +420,7 @@ void PanamaHash<B>::TruncatedFinal(byte 
 {
 	this->ThrowIfInvalidTruncatedSize(size);
 
-	PadLastBlock(this->BLOCKSIZE, 0x01);
+	this->PadLastBlock(this->BLOCKSIZE, 0x01);
 	
 	HashEndianCorrectedBlock(this->m_data);
 
