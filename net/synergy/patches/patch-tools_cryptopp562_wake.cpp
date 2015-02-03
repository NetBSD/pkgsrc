$NetBSD: patch-tools_cryptopp562_wake.cpp,v 1.2 2015/02/03 18:49:34 tnn Exp $

--- ext/cryptopp562/wake.cpp.orig	2014-09-08 10:35:18.000000000 +0000
+++ ext/cryptopp562/wake.cpp
@@ -23,15 +23,15 @@ void WAKE_Base::GenKey(word32 k0, word32
 	signed int x, z, p;	
 	// x and z were declared as "long" in Wheeler's paper, which is a signed type. I don't know if that was intentional, but it's too late to change it now. -- Wei 7/4/2010
 	CRYPTOPP_COMPILE_ASSERT(sizeof(x) == 4);
-	static int tt[10]= {
+	static int tt[8]= {
 		0x726a8f3b,								 // table
-		0xe69a3b5c,
-		0xd3c71fe5,
-		0xab3c73d2,
+		(int)0xe69a3b5c,
+		(int)0xd3c71fe5,
+		(int)0xab3c73d2,
 		0x4d3a8eb3,
 		0x0396d6e8,
 		0x3d4c2f7a,
-		0x9ee27cf3, } ;
+		(int)0x9ee27cf3, } ;
 	t[0] = k0;
 	t[1] = k1;
 	t[2] = k2;
