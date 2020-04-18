$NetBSD: patch-ELF_Config.h,v 1.7 2020/04/18 08:00:50 adam Exp $

Add dummy option for an AArch64 erratum.

--- ELF/Config.h.orig	2020-03-23 15:01:02.000000000 +0000
+++ ELF/Config.h
@@ -150,6 +150,7 @@ struct Configuration {
   bool enableNewDtags;
   bool executeOnly;
   bool exportDynamic;
+  bool fixCortexA53Errata835769;
   bool fixCortexA53Errata843419;
   bool fixCortexA8;
   bool forceBTI;
