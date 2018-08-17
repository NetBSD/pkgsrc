$NetBSD: patch-src_cpu_nec__intf.cpp,v 1.1 2018/08/17 12:54:48 nia Exp $

"Fixing some UB in nec cpu"

Upstream commit: 1c7d1ee57d7853ab8928e12a9eb80efe509ba96c

--- src/cpu/nec_intf.cpp.orig	2018-04-08 06:33:58.000000000 +0000
+++ src/cpu/nec_intf.cpp
@@ -211,8 +211,8 @@ UINT32 VezReadLong(UINT32 a)
 	if ( p )
 		return *(p + (a / 4));
 	else
-		return VezCurrentCPU->ReadHandler(a) + (VezCurrentCPU->ReadHandler(a+1) * 0x100) + 
-			(VezCurrentCPU->ReadHandler(a+2) * 0x10000) + (VezCurrentCPU->ReadHandler(a+3) * 0x1000000);
+		return VezCurrentCPU->ReadHandler(a) + (VezCurrentCPU->ReadHandler(a+1) << 8) +
+			(VezCurrentCPU->ReadHandler(a+2) << 16) + (VezCurrentCPU->ReadHandler(a+3) << 24);
 }
 
 static void VezCheatWrite(UINT32 a, UINT8 d)
