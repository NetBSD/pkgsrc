$NetBSD: patch-source_gnatdoc_gnatdoc-version.ads,v 1.1 2025/09/07 08:08:51 dkazankov Exp $

Set version information

--- source/gnatdoc/gnatdoc-version.ads.orig	2024-10-04 16:57:51.000000000 +0300
+++ source/gnatdoc/gnatdoc-version.ads
@@ -18,6 +18,6 @@
 package GNATdoc.Version is
 
    Version_String : VSS.Strings.Virtual_String :=
-     "%VERSION% (%DATE%)";
+     "25.0 (20241024)";
 
 end GNATdoc.Version;
