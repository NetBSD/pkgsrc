$NetBSD: patch-src_platform_Time.cpp,v 1.1 2016/10/30 10:25:30 maya Exp $

Upstream commit 39fb9a0e3a6888a6a5f040e39896e88750c89065
Use correct parameter type for clock_gettime

Fixes build on OS X

--- src/platform/Time.cpp.orig	2013-10-17 17:25:04.000000000 +0000
+++ src/platform/Time.cpp
@@ -29,7 +29,7 @@ namespace Time {
 
 #include <time.h>
 
-static clock_t clock_id = CLOCK_REALTIME;
+static clockid_t clock_id = CLOCK_REALTIME;
 
 void init() {
 	
