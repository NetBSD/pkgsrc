$NetBSD: patch-kdirstat_kstdcleanup.h,v 1.1 2013/03/28 21:43:12 joerg Exp $

--- kdirstat/kstdcleanup.h.orig	2013-03-27 10:56:59.000000000 +0000
+++ kdirstat/kstdcleanup.h
@@ -18,8 +18,6 @@
 
 // Forward declarations
 class KActionCollection;
-class KDirStat::KCleanup;
-
 
 namespace KDirStat
 {
