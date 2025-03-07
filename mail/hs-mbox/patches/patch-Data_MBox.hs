$NetBSD: patch-Data_MBox.hs,v 1.1 2025/03/07 17:40:26 pho Exp $

Fix build with time >= 1.10.

--- Data/MBox.hs.orig	2025-03-07 17:38:28.347390427 +0000
+++ Data/MBox.hs
@@ -34,7 +34,7 @@ type Header = (T.Text, T.Text)
 parseDateHeader :: T.Text -> Maybe UTCTime
 parseDateHeader txt = listToMaybe . catMaybes $ map tryParse formats where
   header = T.unpack txt
-  tryParse f = parseTime LC.defaultTimeLocale f header
+  tryParse f = parseTimeM True LC.defaultTimeLocale f header
   formats =
     [ "%a, %_d %b %Y %T %z"
     , "%a, %_d %b %Y %T %Z"
