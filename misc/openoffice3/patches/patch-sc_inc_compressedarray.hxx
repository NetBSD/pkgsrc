$NetBSD: patch-sc_inc_compressedarray.hxx,v 1.1 2013/04/01 12:19:14 joerg Exp $

--- sc/inc/compressedarray.hxx.orig	2013-03-30 20:02:54.000000000 +0000
+++ sc/inc/compressedarray.hxx
@@ -553,18 +553,18 @@ public:
 template< typename A, typename D >
 void ScBitMaskCompressedArray<A,D>::AndValue( A nPos, const D& rValueToAnd )
 {
-    const D& rValue = GetValue( nPos);
+    const D& rValue = this->GetValue( nPos);
     if ((rValue & rValueToAnd) != rValue)
-        SetValue( nPos, rValue & rValueToAnd);
+        this->SetValue( nPos, rValue & rValueToAnd);
 }
 
 
 template< typename A, typename D >
 void ScBitMaskCompressedArray<A,D>::OrValue( A nPos, const D& rValueToOr )
 {
-    const D& rValue = GetValue( nPos);
+    const D& rValue = this->GetValue( nPos);
     if ((rValue | rValueToOr) != rValue)
-        SetValue( nPos, rValue | rValueToOr);
+        this->SetValue( nPos, rValue | rValueToOr);
 }
 
 
