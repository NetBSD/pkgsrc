$NetBSD: patch-ELF_Config.h,v 1.10 2025/05/09 05:51:23 adam Exp $

Add dummy option for an AArch64 erratum.

--- ELF/Config.h.orig	2024-09-17 11:26:36.000000000 +0000
+++ ELF/Config.h
@@ -247,6 +247,7 @@ struct Config {
   bool enableNonContiguousRegions;
   bool executeOnly;
   bool exportDynamic;
+  bool fixCortexA53Errata835769;
   bool fixCortexA53Errata843419;
   bool fixCortexA8;
   bool formatBinary = false;
