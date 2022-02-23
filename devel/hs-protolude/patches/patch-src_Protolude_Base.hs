$NetBSD: patch-src_Protolude_Base.hs,v 1.1 2022/02/23 16:18:22 pho Exp $

https://github.com/protolude/protolude/pull/126

--- src/Protolude/Base.hs.orig	2022-02-20 14:25:46.651110411 +0000
+++ src/Protolude/Base.hs
@@ -67,7 +67,7 @@ import GHC.Real as Base (
   , fromIntegral
   , fromRational
   , gcd
-#if MIN_VERSION_base(4,9,0)
+#if MIN_VERSION_base(4,9,0) && !MIN_VERSION_base(4,15,0)
   , gcdInt'
   , gcdWord'
 #endif
