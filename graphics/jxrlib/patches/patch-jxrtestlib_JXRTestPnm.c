$NetBSD: patch-jxrtestlib_JXRTestPnm.c,v 1.1 2019/11/25 21:07:19 nros Exp $
* fix warning
--- jxrtestlib/JXRTestPnm.c.orig	2019-11-16 13:10:49.180538241 +0000
+++ jxrtestlib/JXRTestPnm.c
@@ -27,7 +27,7 @@
 //*@@@---@@@@******************************************************************
 #ifndef ANSI
 #define _CRT_SECURE_NO_WARNINGS
-#endif ANSI
+#endif
 
 #include <stdlib.h>
 
