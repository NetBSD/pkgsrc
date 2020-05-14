$NetBSD: patch-dj3320.cpp,v 1.1 2020/05/14 19:01:26 joerg Exp $

--- dj3320.cpp.orig	2020-05-10 23:09:20.918727851 +0000
+++ dj3320.cpp
@@ -400,7 +400,7 @@ DISPLAY_STATUS DJ3320::ParseError (BYTE 
 {
     DRIVER_ERROR err = NO_ERROR;
     BYTE byDevIDBuffer[DevIDBuffSize];
-    char *pcStr = NULL;
+    const char *pcStr = NULL;
     BYTE byStatus1, byStatus2;
 
     memset(byDevIDBuffer, 0, sizeof(byDevIDBuffer));
