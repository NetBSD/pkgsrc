$NetBSD: patch-src_webquerypubmed.h,v 1.1 2013/03/28 21:43:10 joerg Exp $

--- src/webquerypubmed.h.orig	2013-03-27 10:50:22.000000000 +0000
+++ src/webquerypubmed.h
@@ -29,7 +29,6 @@
 class QStringList;
 class QDomElement;
 class QDate;
-class BibTeX::File;
 
 namespace KBibTeX
 {
