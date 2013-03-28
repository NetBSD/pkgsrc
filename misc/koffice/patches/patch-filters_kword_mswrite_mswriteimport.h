$NetBSD: patch-filters_kword_mswrite_mswriteimport.h,v 1.1 2013/03/28 21:43:09 joerg Exp $

--- filters/kword/mswrite/mswriteimport.h.orig	2013-03-28 15:51:07.000000000 +0000
+++ filters/kword/mswrite/mswriteimport.h
@@ -23,7 +23,6 @@
 #include <KoFilter.h>
 
 class WRIDevice;
-class MSWrite::InternalParser;
 class KWordGenerator;
 
 class MSWriteImport : public KoFilter
