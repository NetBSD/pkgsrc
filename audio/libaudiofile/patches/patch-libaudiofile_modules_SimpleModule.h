$NetBSD: patch-libaudiofile_modules_SimpleModule.h,v 1.3 2016/12/19 00:14:43 maya Exp $

Left shift of a negative number is UB and doesn't build (-fpermissive)
Switch with functionally identical but well-defined operation.
(same function used upstream)

Just define it in the accessor rather than a cstatic global (which isn't
actually cstatic, which is UB and optimized away at least by GCC)

--- libaudiofile/modules/SimpleModule.h.orig	2013-03-06 05:30:03.000000000 +0000
+++ libaudiofile/modules/SimpleModule.h
@@ -122,17 +122,24 @@ struct signConverter
 	typedef typename IntTypes<Format>::SignedType SignedType;
 	typedef typename IntTypes<Format>::UnsignedType UnsignedType;
 
-	static const int kScaleBits = (Format + 1) * CHAR_BIT - 1;
-	static const int kMinSignedValue = -1 << kScaleBits;
-
 	struct signedToUnsigned : public std::unary_function<SignedType, UnsignedType>
 	{
-		UnsignedType operator()(SignedType x) { return x - kMinSignedValue; }
+		UnsignedType operator()(SignedType x) {
+			int kScaleBits = (Format + 1) * CHAR_BIT - 1;
+			int kMaxSignedValue = (((1 << (kScaleBits - 1)) - 1) << 1) + 1;
+			int kMinSignedValue = -kMaxSignedValue - 1;
+			return x - kMinSignedValue;
+		}
 	};
 
 	struct unsignedToSigned : public std::unary_function<SignedType, UnsignedType>
 	{
-		SignedType operator()(UnsignedType x) { return x + kMinSignedValue; }
+		SignedType operator()(UnsignedType x) {
+			int kScaleBits = (Format + 1) * CHAR_BIT - 1;
+			int kMaxSignedValue = (((1 << (kScaleBits - 1)) - 1) << 1) + 1;
+			int kMinSignedValue = -kMaxSignedValue - 1;
+			return x + kMinSignedValue;
+		}
 	};
 };
 
