$NetBSD: patch-src_gnatformat.ads,v 1.1 2025/09/07 07:51:55 dkazankov Exp $

Set version information

--- src/gnatformat.ads.orig	2024-09-24 18:34:53.000000000 +0300
+++ src/gnatformat.ads
@@ -11,8 +11,8 @@
 
    Gnatformat_Trace : GNATCOLL.Traces.Trace_Handle :=
      GNATCOLL.Traces.Create ("GNATFORMAT", GNATCOLL.Traces.Off);
-   Version    : constant String := "debug";
-   Build_Date : constant String := "debug";
+   Version    : constant String := "25.0";
+   Build_Date : constant String := "20241031";
 
    type Supported_Languages is (Ada_Language);
 
