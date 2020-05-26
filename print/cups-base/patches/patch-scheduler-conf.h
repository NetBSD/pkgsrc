$NetBSD: patch-scheduler-conf.h,v 1.2 2020/05/26 08:36:56 triaxx Exp $

Add a PidFile configuration directive to write a PID file.

--- scheduler/conf.h.orig	2017-03-28 20:26:53.000000000 +0200
+++ scheduler/conf.h	2017-07-17 17:25:02.000000000 +0200
@@ -131,6 +131,8 @@
 					/* Cache file directory */
 			*DataDir		VALUE(NULL),
 					/* Data file directory */
+			*PidFile		VALUE(NULL),
+					/* PID file */
 			*DefaultLanguage	VALUE(NULL),
 					/* Default language encoding */
 			*DefaultLocale		VALUE(NULL),
