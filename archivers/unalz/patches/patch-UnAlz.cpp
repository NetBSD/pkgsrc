$NetBSD: patch-UnAlz.cpp,v 1.1 2017/06/26 09:48:34 adam Exp $

Fix for newer zlib.

--- UnAlz.cpp.orig	2017-06-26 09:30:31.000000000 +0000
+++ UnAlz.cpp
@@ -1907,7 +1907,7 @@ void CUnAlz::DecryptingData(int nSize, B
 ////////////////////////////////////////////////////////////////////////////////////////////////////
 UINT32 CUnAlz::CRC32(UINT32 l, BYTE c)
 {
-	const unsigned long *CRC_TABLE = get_crc_table();
+	const unsigned int *CRC_TABLE = (unsigned int *)get_crc_table();
 	return CRC_TABLE[(l ^ c) & 0xff] ^ (l >> 8);
 }
 
