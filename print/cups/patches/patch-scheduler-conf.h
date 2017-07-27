$NetBSD: patch-scheduler-conf.h,v 1.1 2017/07/27 08:54:26 wiz Exp $

Add a PidFile configuration directive to write a PID file.

--- scheduler/conf.h.orig	2017-03-28 20:26:53.000000000 +0200
+++ scheduler/conf.h	2017-07-17 17:25:02.000000000 +0200
@@ -134,6 +134,8 @@
 					/* Cache file directory */
 			*DataDir		VALUE(NULL),
 					/* Data file directory */
+			*PidFile		VALUE(NULL),
+					/* PID file */
 			*DefaultLanguage	VALUE(NULL),
 					/* Default language encoding */
 			*DefaultLocale		VALUE(NULL),
