$NetBSD: patch-jxrtestlib_JXRTestHdr.c,v 1.1 2019/11/25 21:07:19 nros Exp $
* fix warning
--- jxrtestlib/JXRTestHdr.c.orig	2013-03-20 16:40:08.000000000 +0000
+++ jxrtestlib/JXRTestHdr.c
@@ -27,7 +27,7 @@
 //*@@@---@@@@******************************************************************
 #ifndef ANSI
 #define _CRT_SECURE_NO_WARNINGS
-#endif ANSI
+#endif
 
 #include <stdlib.h>
 #include <string.h>
