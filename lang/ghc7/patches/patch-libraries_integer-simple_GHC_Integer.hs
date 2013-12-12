$NetBSD: patch-libraries_integer-simple_GHC_Integer.hs,v 1.1 2013/12/12 12:47:17 obache Exp $

Missing functions: already fixed in the upstream.


--- libraries/integer-simple/GHC/Integer.hs.orig	2013-02-13 18:50:32.000000000 +0000
+++ libraries/integer-simple/GHC/Integer.hs
@@ -27,6 +27,7 @@ module GHC.Integer (
     plusInteger, minusInteger, timesInteger, negateInteger,
     eqInteger, neqInteger, absInteger, signumInteger,
     leInteger, gtInteger, ltInteger, geInteger, compareInteger,
+    divInteger, modInteger,
     divModInteger, quotRemInteger, quotInteger, remInteger,
     encodeFloatInteger, decodeFloatInteger, floatFromInteger,
     encodeDoubleInteger, decodeDoubleInteger, doubleFromInteger,
