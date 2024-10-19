$NetBSD: patch-src_bin_exrmetrics_exrmetrics.cpp,v 1.2 2024/10/19 11:55:44 wiz Exp $

Fix build on NetBSD.
https://github.com/AcademySoftwareFoundation/openexr/issues/1889

--- src/bin/exrmetrics/exrmetrics.cpp.orig	2024-09-26 23:34:32.000000000 +0000
+++ src/bin/exrmetrics/exrmetrics.cpp
@@ -482,7 +482,7 @@ exrmetrics (
     }
     else { compression = outHeader.compression (); }
 
-    if (!isinf (level) && level >= -1)
+    if (!std::isinf (level) && level >= -1)
     {
         switch (outHeader.compression ())
         {
