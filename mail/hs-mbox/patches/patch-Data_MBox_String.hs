$NetBSD: patch-Data_MBox_String.hs,v 1.1 2025/03/07 17:40:26 pho Exp $

Fix build with time >= 1.10.

--- Data/MBox/String.hs.orig	2025-03-07 17:36:51.039504849 +0000
+++ Data/MBox/String.hs
@@ -31,7 +31,7 @@ type Header = (String, String)
 -- | Reads a date header as a UTCTime
 parseDateHeader :: String -> Maybe UTCTime
 parseDateHeader header = listToMaybe . catMaybes $ map tryParse formats where
-  tryParse f = parseTime LC.defaultTimeLocale f header
+  tryParse f = parseTimeM True LC.defaultTimeLocale f header
   formats =
     [ "%a, %_d %b %Y %T %z"
     , "%a, %_d %b %Y %T %Z"
