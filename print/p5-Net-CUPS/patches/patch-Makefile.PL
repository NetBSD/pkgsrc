$NetBSD: patch-Makefile.PL,v 1.1 2025/08/31 12:45:24 wiz Exp $

Fix build with libcupsfilters 2.x. From
https://launchpadlibrarian.net/698897992/libnet-cups-perl_0.64-3_0.64-3ubuntu1.diff.gz

--- Makefile.PL.orig	2016-07-21 06:49:51.595781877 +0000
+++ Makefile.PL
@@ -82,6 +82,12 @@ if  (eval {require ExtUtils::Constant; 1
 
   my @names = ( 
 		{ name => "AF_LOCAL", macro => "1" },
+		{ name => "CF_IMAGE_BLACK", macro => "1" },
+		{ name => "CF_IMAGE_CMY", macro => "1" },
+		{ name => "CF_IMAGE_CMYK", macro => "1" },
+		{ name => "CF_IMAGE_RGB", macro => "1" },
+		{ name => "CF_IMAGE_RGB_CMYK", macro => "1" },
+		{ name => "CF_IMAGE_WHITE", macro => "1" },
 		{ name => "CUPS_ACCEPT_JOBS", macro => "1" },
 		{ name => "CUPS_ADD_CLASS", macro => "1" },
 		{ name => "CUPS_ADD_MODIFY_CLASS", macro => "1" },
@@ -112,12 +118,6 @@ if  (eval {require ExtUtils::Constant; 1
 		{ name => "CUPS_GET_DEVICES", macro => "1" },
 		{ name => "CUPS_GET_PPDS", macro => "1" },
 		{ name => "CUPS_GET_PRINTERS", macro => "1" },
-		{ name => "CUPS_IMAGE_BLACK", macro => "1" },
-		{ name => "CUPS_IMAGE_CMY", macro => "1" },
-		{ name => "CUPS_IMAGE_CMYK", macro => "1" },
-		{ name => "CUPS_IMAGE_RGB", macro => "1" },
-		{ name => "CUPS_IMAGE_RGB_CMYK", macro => "1" },
-		{ name => "CUPS_IMAGE_WHITE", macro => "1" },
 		{ name => "CUPS_ISO8859_1", macro => "1" },
 		{ name => "CUPS_ISO8859_10", macro => "1" },
 		{ name => "CUPS_ISO8859_11", macro => "1" },
