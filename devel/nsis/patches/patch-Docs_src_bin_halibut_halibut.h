$NetBSD: patch-Docs_src_bin_halibut_halibut.h,v 1.1 2023/07/27 11:34:40 tnn Exp $

ld: build/urelease/halibut/bk_xhtml.o:(.rodata+0x0): multiple definition of `version'; build/urelease/halibut/biblio.o:(.rodata+0x0): first defined here

--- Docs/src/bin/halibut/halibut.h.orig	2011-12-03 18:16:36.000000000 +0000
+++ Docs/src/bin/halibut/halibut.h
@@ -269,7 +269,7 @@ void licence(void);
  * version.c
  */
 void initversionstring(void);
-const char *const version;
+extern const char *const version;
 
 /*
  * misc.c
