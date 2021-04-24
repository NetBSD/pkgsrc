$NetBSD: patch-Crypto_Number_Compat.hs,v 1.1 2021/04/24 12:55:43 pho Exp $

Fix build with GHC 9. integer-gmp is now deprecated in favor of
ghc-bignum, and some *internal* functions have apparently been
removed. Why does it use the internals in the first place? This is an
upstream issue that has been reported but not fixed yet:

https://github.com/haskell-crypto/cryptonite/issues/340

--- Crypto/Number/Compat.hs.orig	2021-04-24 12:33:16.453915356 +0000
+++ Crypto/Number/Compat.hs
@@ -72,7 +72,9 @@ gmpLog2 _ = GmpUnsupported
 -- | Compute the power modulus using extra security to remain constant
 -- time wise through GMP
 gmpPowModSecInteger :: Integer -> Integer -> Integer -> GmpSupported Integer
-#if MIN_VERSION_integer_gmp(1,0,2)
+#if MIN_VERSION_integer_gmp(1,1,0)
+gmpPowModSecInteger b e m = GmpSupported (powModInteger b e m)
+#elif MIN_VERSION_integer_gmp(1,0,2)
 gmpPowModSecInteger b e m = GmpSupported (powModSecInteger b e m)
 #elif MIN_VERSION_integer_gmp(1,0,0)
 gmpPowModSecInteger _ _ _ = GmpUnsupported
@@ -103,7 +105,9 @@ gmpInverse _ _ = GmpUnsupported
 
 -- | Get the next prime from a specific value through GMP
 gmpNextPrime :: Integer -> GmpSupported Integer
-#if MIN_VERSION_integer_gmp(0,5,1)
+#if MIN_VERSION_integer_gmp(1,1,0)
+gmpNextPrime _ = GmpUnsupported
+#elif MIN_VERSION_integer_gmp(0,5,1)
 gmpNextPrime n = GmpSupported (nextPrimeInteger n)
 #else
 gmpNextPrime _ = GmpUnsupported
@@ -111,7 +115,9 @@ gmpNextPrime _ = GmpUnsupported
 
 -- | Test if a number is prime using Miller Rabin
 gmpTestPrimeMillerRabin :: Int -> Integer -> GmpSupported Bool
-#if MIN_VERSION_integer_gmp(0,5,1)
+#if MIN_VERSION_integer_gmp(1,1,0)
+gmpTestPrimeMillerRabin _ _ = GmpUnsupported
+#elif MIN_VERSION_integer_gmp(0,5,1)
 gmpTestPrimeMillerRabin (I# tries) !n = GmpSupported $
     case testPrimeInteger n tries of
         0# -> False
