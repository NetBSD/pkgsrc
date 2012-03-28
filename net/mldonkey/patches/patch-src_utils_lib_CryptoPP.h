$NetBSD: patch-src_utils_lib_CryptoPP.h,v 1.1 2012/03/28 20:40:38 wiz Exp $

Fix build with clang-3.1.

--- src/utils/lib/CryptoPP.h.orig	2011-05-07 18:40:00.000000000 +0000
+++ src/utils/lib/CryptoPP.h
@@ -2633,7 +2633,7 @@ public:
 
 	pointer allocate(size_type n, const void * = NULL)
 	{
-		CheckSize(n);
+		this->CheckSize(n);
 		if (n == 0)
 			return NULL;
 		return new T[n];
@@ -5612,7 +5612,7 @@ template <class T, class B, class BASE> 
 {
 	this->ThrowIfInvalidTruncatedSize(size);
 
-	PadLastBlock(this->BlockSize() - 2*sizeof(HashWordType));
+	this->PadLastBlock(this->BlockSize() - 2*sizeof(HashWordType));
 	CorrectEndianess(this->m_data, this->m_data, this->BlockSize() - 2*sizeof(HashWordType));
 
 	this->m_data[this->m_data.size()-2] = B::ToEnum() ? this->GetBitCountHi() : this->GetBitCountLo();
