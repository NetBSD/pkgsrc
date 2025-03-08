$NetBSD: patch-compiler_src_Reporting_Doc.hs,v 1.1 2025/03/08 07:29:13 pho Exp $

Fix build with ansi-wl-pprint >= 1.0. This isn't a proper fix, because it
just discards ANSI SGRs. But let's just hope that (seemingly half-dead)
upstream fixes this in the future.

--- compiler/src/Reporting/Doc.hs.orig	2025-03-08 03:42:32.184407808 +0000
+++ compiler/src/Reporting/Doc.hs
@@ -48,10 +48,12 @@ import Prelude hiding (cycle)
 import qualified Data.List as List
 import Data.Monoid ((<>))
 import qualified Data.Name as Name
+import qualified Data.Text as T
 import qualified System.Console.ANSI.Types as Ansi
 import qualified System.Info as Info
 import System.IO (Handle)
 import qualified Text.PrettyPrint.ANSI.Leijen as P
+import qualified Prettyprinter as PP
 
 import qualified Data.Index as Index
 import qualified Elm.Package as Pkg
@@ -309,26 +311,28 @@ data Color
 toJsonHelp :: Style -> [String] -> P.SimpleDoc -> [E.Value]
 toJsonHelp style revChunks simpleDoc =
   case simpleDoc of
-    P.SFail ->
+    PP.SFail ->
       error $
         "according to the main implementation, @SFail@ can not\
         \ appear uncaught in a rendered @SimpleDoc@"
 
-    P.SEmpty ->
+    PP.SEmpty ->
       [ encodeChunks style revChunks ]
 
-    P.SChar char rest ->
+    PP.SChar char rest ->
       toJsonHelp style ([char] : revChunks) rest
 
-    P.SText _ string rest ->
-      toJsonHelp style (string : revChunks) rest
+    PP.SText _ string rest ->
+      toJsonHelp style (T.unpack string : revChunks) rest
 
-    P.SLine indent rest ->
+    PP.SLine indent rest ->
       toJsonHelp style (replicate indent ' ' : "\n" : revChunks) rest
 
-    P.SSGR sgrs rest ->
-      encodeChunks style revChunks : toJsonHelp (sgrToStyle sgrs style) [] rest
+    PP.SAnnPush _ rest ->
+      encodeChunks style revChunks : toJsonHelp style [] rest
 
+    PP.SAnnPop rest ->
+      encodeChunks style revChunks : toJsonHelp style [] rest
 
 sgrToStyle :: [Ansi.SGR] -> Style -> Style
 sgrToStyle sgrs style@(Style bold underline color) =
