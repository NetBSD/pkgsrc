$NetBSD: patch-djgenericvip.cpp,v 1.1 2015/04/26 13:28:23 joerg Exp $

--- djgenericvip.cpp.orig	2015-04-26 12:32:41.000000000 +0000
+++ djgenericvip.cpp
@@ -371,7 +371,7 @@ BOOL DJGenericVIP::HagakiFeedPresent(BOO
     // skip over ";S:<version=2bytes><topcover><inklid><duplexer>"
     pStr += 8;
     BYTE b = *pStr;
-    return (b & 4 == 4);
+    return (b & 4) == 4;
 }
 
 #ifdef APDK_AUTODUPLEX
@@ -402,7 +402,7 @@ BOOL DJGenericVIP::HagakiFeedDuplexerPre
     // skip over ";S:<version=2bytes><topcover><inklid>"
     pStr += 6;
     BYTE b = *pStr;
-    return (b & 4 == 4);
+    return (b & 4) == 4;
 }
 #endif
 
