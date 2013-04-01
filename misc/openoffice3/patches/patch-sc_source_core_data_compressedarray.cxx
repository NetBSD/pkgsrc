$NetBSD: patch-sc_source_core_data_compressedarray.cxx,v 1.1 2013/04/01 12:19:14 joerg Exp $

--- sc/source/core/data/compressedarray.cxx.orig	2013-03-30 20:02:28.000000000 +0000
+++ sc/source/core/data/compressedarray.cxx
@@ -370,7 +370,7 @@ A ScCompressedArray<A,D>::GetLastUnequal
 template< typename A, typename D >
 unsigned long ScSummableCompressedArray<A,D>::SumValues( A nStart, A nEnd ) const
 {
-    size_t nIndex = Search( nStart);
+    size_t nIndex = this->Search( nStart);
     unsigned long nSum = SumValuesContinuation( nStart, nEnd, nIndex);
     if (nEnd > this->nMaxAccess)
         nSum += this->pData[this->nCount-1].aValue * (nEnd - this->nMaxAccess);
@@ -432,17 +432,17 @@ void ScBitMaskCompressedArray<A,D>::AndV
     if (nStart > nEnd)
         return;
 
-    size_t nIndex = Search( nStart);
+    size_t nIndex = this->Search( nStart);
     do
     {
         if ((this->pData[nIndex].aValue & rValueToAnd) != this->pData[nIndex].aValue)
         {
             A nS = ::std::max( (nIndex>0 ? this->pData[nIndex-1].nEnd+1 : 0), nStart);
             A nE = ::std::min( this->pData[nIndex].nEnd, nEnd);
-            SetValue( nS, nE, this->pData[nIndex].aValue & rValueToAnd);
+            this->SetValue( nS, nE, this->pData[nIndex].aValue & rValueToAnd);
             if (nE >= nEnd)
                 break;  // while
-            nIndex = Search( nE + 1);
+            nIndex = this->Search( nE + 1);
         }
         else if (this->pData[nIndex].nEnd >= nEnd)
             break;  // while
@@ -459,17 +459,17 @@ void ScBitMaskCompressedArray<A,D>::OrVa
     if (nStart > nEnd)
         return;
 
-    size_t nIndex = Search( nStart);
+    size_t nIndex = this->Search( nStart);
     do
     {
         if ((this->pData[nIndex].aValue | rValueToOr) != this->pData[nIndex].aValue)
         {
             A nS = ::std::max( (nIndex>0 ? this->pData[nIndex-1].nEnd+1 : 0), nStart);
             A nE = ::std::min( this->pData[nIndex].nEnd, nEnd);
-            SetValue( nS, nE, this->pData[nIndex].aValue | rValueToOr);
+            this->SetValue( nS, nE, this->pData[nIndex].aValue | rValueToOr);
             if (nE >= nEnd)
                 break;  // while
-            nIndex = Search( nE + 1);
+            nIndex = this->Search( nE + 1);
         }
         else if (this->pData[nIndex].nEnd >= nEnd)
             break;  // while
@@ -494,7 +494,7 @@ void ScBitMaskCompressedArray<A,D>::Copy
         nRegionEnd -= nSourceDy;
         if (nRegionEnd > nEnd)
             nRegionEnd = nEnd;
-        SetValue( j, nRegionEnd, rValue & rValueToAnd);
+        this->SetValue( j, nRegionEnd, rValue & rValueToAnd);
         j = nRegionEnd;
     }
 }
@@ -515,7 +515,7 @@ void ScBitMaskCompressedArray<A,D>::Copy
         nRegionEnd -= nSourceDy;
         if (nRegionEnd > nEnd)
             nRegionEnd = nEnd;
-        SetValue( j, nRegionEnd, rValue | rValueToOr);
+        this->SetValue( j, nRegionEnd, rValue | rValueToOr);
         j = nRegionEnd;
     }
 }
@@ -526,7 +526,7 @@ A ScBitMaskCompressedArray<A,D>::GetBitS
         const D& rBitMask, const D& rMaskedCompare ) const
 {
     A nStart = ::std::numeric_limits<A>::max();
-    size_t nIndex = Search( nEnd);
+    size_t nIndex = this->Search( nEnd);
     while ((this->pData[nIndex].aValue & rBitMask) == rMaskedCompare)
     {
         if (nIndex > 0)
@@ -549,7 +549,7 @@ A ScBitMaskCompressedArray<A,D>::GetBitS
         const D& rBitMask, const D& rMaskedCompare ) const
 {
     A nEnd = ::std::numeric_limits<A>::max();
-    size_t nIndex = Search( nStart);
+    size_t nIndex = this->Search( nStart);
     while (nIndex < this->nCount && (this->pData[nIndex].aValue & rBitMask) ==
             rMaskedCompare)
     {
@@ -564,7 +564,7 @@ template< typename A, typename D >
 A ScBitMaskCompressedArray<A,D>::GetFirstForCondition( A nStart, A nEnd,
         const D& rBitMask, const D& rMaskedCompare ) const
 {
-    size_t nIndex = Search( nStart);
+    size_t nIndex = this->Search( nStart);
     do
     {
         if ((this->pData[nIndex].aValue & rBitMask) == rMaskedCompare)
@@ -584,7 +584,7 @@ template< typename A, typename D >
 A ScBitMaskCompressedArray<A,D>::GetLastForCondition( A nStart, A nEnd,
         const D& rBitMask, const D& rMaskedCompare ) const
 {
-    size_t nIndex = Search( nEnd);
+    size_t nIndex = this->Search( nEnd);
     while (1)
     {
         if ((this->pData[nIndex].aValue & rBitMask) == rMaskedCompare)
@@ -608,7 +608,7 @@ A ScBitMaskCompressedArray<A,D>::CountFo
         const D& rBitMask, const D& rMaskedCompare ) const
 {
     A nRet = 0;
-    size_t nIndex = Search( nStart);
+    size_t nIndex = this->Search( nStart);
     do
     {
         if ((this->pData[nIndex].aValue & rBitMask) == rMaskedCompare)
@@ -631,7 +631,7 @@ size_t ScBitMaskCompressedArray<A,D>::Fi
         A * pArray, size_t nArraySize ) const
 {
     size_t nUsed = 0;
-    size_t nIndex = Search( nStart);
+    size_t nIndex = this->Search( nStart);
     while (nIndex < this->nCount && nUsed < nArraySize)
     {
         if ((this->pData[nIndex].aValue & rBitMask) == rMaskedCompare)
@@ -653,7 +653,7 @@ template< typename A, typename D >
 bool ScBitMaskCompressedArray<A,D>::HasCondition( A nStart, A nEnd,
         const D& rBitMask, const D& rMaskedCompare ) const
 {
-    size_t nIndex = Search( nStart);
+    size_t nIndex = this->Search( nStart);
     do
     {
         if ((this->pData[nIndex].aValue & rBitMask) == rMaskedCompare)
@@ -671,7 +671,7 @@ A ScBitMaskCompressedArray<A,D>::CountFo
         const D& rBitMask ) const
 {
     A nRet = 0;
-    size_t nIndex = Search( nStart);
+    size_t nIndex = this->Search( nStart);
     do
     {
         if ((this->pData[nIndex].aValue & rBitMask) != 0)
@@ -725,7 +725,7 @@ unsigned long ScBitMaskCompressedArray<A
 {
     unsigned long nSum = 0;
     A nS = nStart;
-    size_t nIndex1 = Search( nStart);
+    size_t nIndex1 = this->Search( nStart);
     size_t nIndex2 = rArray.Search( nStart);
     do
     {
@@ -759,7 +759,7 @@ unsigned long ScBitMaskCompressedArray<A
 {
     unsigned long nSum = 0;
     A nS = nStart;
-    size_t nIndex1 = Search( nStart);
+    size_t nIndex1 = this->Search( nStart);
     size_t nIndex2 = rArray.Search( nStart);
     do
     {
