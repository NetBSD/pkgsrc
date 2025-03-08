$NetBSD: patch-compiler_src_Parse_Variable.hs,v 1.1 2025/03/08 07:29:13 pho Exp $

Fix build with GHC >= 9.4:
https://github.com/elm/compiler/commit/0421dfbe48e53d880a401e201890eac0b3de5f06

--- compiler/src/Parse/Variable.hs.orig	2019-10-20 14:31:43.000000000 +0000
+++ compiler/src/Parse/Variable.hs
@@ -21,7 +21,7 @@ import qualified Data.Name as Name
 import qualified Data.Set as Set
 import Data.Word (Word8)
 import Foreign.Ptr (Ptr, plusPtr)
-import GHC.Exts (Char(C#), Int#, (+#), (-#), chr#, uncheckedIShiftL#, word2Int#)
+import GHC.Exts (Char(C#), Int#, (+#), (-#), chr#, uncheckedIShiftL#, word2Int#, word8ToWord#)
 import GHC.Word (Word8(W8#))
 
 import qualified AST.Source as Src
@@ -384,4 +384,4 @@ chr4 pos firstWord =
 
 unpack :: Word8 -> Int#
 unpack (W8# word#) =
-  word2Int# word#
+  word2Int# (word8ToWord# word#)
