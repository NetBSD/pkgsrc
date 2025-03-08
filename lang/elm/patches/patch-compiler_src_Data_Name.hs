$NetBSD: patch-compiler_src_Data_Name.hs,v 1.1 2025/03/08 07:29:13 pho Exp $

Fix build with GHC >= 9.4:
https://github.com/elm/compiler/commit/0421dfbe48e53d880a401e201890eac0b3de5f06

--- compiler/src/Data/Name.hs.orig	2019-10-20 14:31:43.000000000 +0000
+++ compiler/src/Data/Name.hs
@@ -241,7 +241,7 @@ fromTypeVariable name@(Utf8.Utf8 ba#) in
   else
     let
       len# = sizeofByteArray# ba#
-      end# = indexWord8Array# ba# (len# -# 1#)
+      end# = word8ToWord# (indexWord8Array# ba# (len# -# 1#))
     in
     if isTrue# (leWord# 0x30## end#) && isTrue# (leWord# end# 0x39##) then
       runST
@@ -316,11 +316,11 @@ fromManyNames names =
         ST $ \s ->
           case newByteArray# (len# +# 3#) s of
             (# s, mba# #) ->
-              case writeWord8Array# mba# 0# 0x5F## {-_-} s of
+              case writeWord8Array# mba# 0# (wordToWord8# 0x5F##) {-_-} s of
                 s ->
-                  case writeWord8Array# mba# 1# 0x4D## {-M-} s of
+                  case writeWord8Array# mba# 1# (wordToWord8# 0x4D##) {-M-} s of
                     s ->
-                      case writeWord8Array# mba# 2# 0x24## {-$-} s of
+                      case writeWord8Array# mba# 2# (wordToWord8# 0x24##) {-$-} s of
                         s ->
                           case copyByteArray# ba# 0# mba# 3# len# s of
                             s ->
