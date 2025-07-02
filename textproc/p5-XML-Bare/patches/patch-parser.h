$NetBSD: patch-parser.h,v 1.1 2025/07/02 03:52:04 markd Exp $

<stdlib.h> for malloc() and free()

--- parser.h.orig	2013-04-30 02:00:00.000000000 +0000
+++ parser.h
@@ -1,6 +1,4 @@
-#ifdef WIN32
 #include<stdlib.h>
-#endif
 
 #ifndef NULL
   #define NULL 0x00
