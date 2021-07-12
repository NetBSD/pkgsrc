$NetBSD: patch-ELF_Config.h,v 1.8 2021/07/12 18:47:15 adam Exp $

Add dummy option for an AArch64 erratum.

--- ELF/Config.h.orig	2020-10-07 10:10:48.000000000 +0000
+++ ELF/Config.h
@@ -156,6 +156,7 @@ struct Configuration {
   bool enableNewDtags;
   bool executeOnly;
   bool exportDynamic;
+  bool fixCortexA53Errata835769;
   bool fixCortexA53Errata843419;
   bool fixCortexA8;
   bool formatBinary = false;
