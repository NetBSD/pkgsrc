$NetBSD: patch-src_NULLTracert.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/NULLTracert.cc.orig	2020-03-27 18:19:57.000133342 +0000
+++ src/NULLTracert.cc
@@ -7,7 +7,7 @@
 
 NULLTracert::NULLTracert () {
 	printf("tracert impl\n");	
-  log(INFO, "NULL algo");
+  mylog(INFO, "NULL algo");
 }
 
 /**
