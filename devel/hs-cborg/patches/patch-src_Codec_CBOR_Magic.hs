$NetBSD: patch-src_Codec_CBOR_Magic.hs,v 1.1 2022/08/22 10:25:08 wiz Exp $

 Fix compatibility with primitive 0.7.4.0
https://github.com/well-typed/cborg/pull/292/files

--- src/Codec/CBOR/Magic.hs.orig	2001-09-09 01:46:40.000000000 +0000
+++ src/Codec/CBOR/Magic.hs
@@ -109,7 +109,7 @@ import           Data.ByteString (ByteSt
 import qualified Data.ByteString          as BS
 import qualified Data.ByteString.Internal as BS
 import qualified Data.ByteString.Unsafe   as BS
-import           Data.Primitive.ByteArray as Prim hiding (copyByteArrayToPtr)
+import           Data.Primitive.ByteArray as Prim hiding (copyByteArrayToPtr, copyPtrToMutableByteArray)
 
 import           Foreign.ForeignPtr (withForeignPtr)
 import           Foreign.C (CUShort)
