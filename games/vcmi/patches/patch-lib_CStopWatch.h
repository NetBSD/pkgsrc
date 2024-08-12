$NetBSD: patch-lib_CStopWatch.h,v 1.1 2024/08/12 11:19:25 nia Exp $

Add support for NetBSD.

--- lib/CStopWatch.h.orig	2024-08-11 18:14:07.468508472 +0000
+++ lib/CStopWatch.h
@@ -9,7 +9,7 @@
  */
 #pragma once
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 	#include <sys/types.h>
 	#include <sys/time.h>
 	#include <sys/resource.h>
