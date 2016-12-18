$NetBSD: patch-libaudiofile_modules_SimpleModule.h,v 1.2 2016/12/18 23:40:23 maya Exp $

Left shift of a negative number is UB and doesn't build (-fpermissive)
Switch with functionally identical but well-defined operation.

--- libaudiofile/modules/SimpleModule.h.orig	2013-03-06 05:30:03.000000000 +0000
+++ libaudiofile/modules/SimpleModule.h
@@ -123,7 +123,7 @@ struct signConverter
 	typedef typename IntTypes<Format>::UnsignedType UnsignedType;
 
 	static const int kScaleBits = (Format + 1) * CHAR_BIT - 1;
-	static const int kMinSignedValue = -1 << kScaleBits;
+	static const int kMinSignedValue = -(1 << kScaleBits);
 
 	struct signedToUnsigned : public std::unary_function<SignedType, UnsignedType>
 	{
