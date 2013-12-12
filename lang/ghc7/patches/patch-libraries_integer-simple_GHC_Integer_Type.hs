$NetBSD: patch-libraries_integer-simple_GHC_Integer_Type.hs,v 1.1 2013/12/12 12:47:17 obache Exp $

Missing functions: already fixed in the upstream.


--- libraries/integer-simple/GHC/Integer/Type.hs.orig	2013-02-13 18:45:55.000000000 +0000
+++ libraries/integer-simple/GHC/Integer/Type.hs
@@ -370,6 +370,16 @@ n `divModInteger` d =
             then (# q `minusInteger` oneInteger, r `plusInteger` d #)
             else (# q, r #)
 
+{-# NOINLINE divInteger #-}
+divInteger :: Integer -> Integer -> Integer
+n `divInteger` d = quotient
+    where (# quotient, _ #) = n `divModInteger` d
+
+{-# NOINLINE modInteger #-}
+modInteger :: Integer -> Integer -> Integer
+n `modInteger` d = modulus
+    where (# _, modulus #) = n `divModInteger` d
+
 {-# NOINLINE quotRemInteger #-}
 quotRemInteger :: Integer -> Integer -> (# Integer, Integer #)
 Naught      `quotRemInteger` (!_)        = (# Naught, Naught #)
