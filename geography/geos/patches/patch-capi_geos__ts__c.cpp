$NetBSD: patch-capi_geos__ts__c.cpp,v 1.1 2015/09/08 18:48:04 joerg Exp $

--- capi/geos_ts_c.cpp.orig	2015-09-08 16:31:02.000000000 +0000
+++ capi/geos_ts_c.cpp
@@ -214,7 +214,7 @@ typedef struct GEOSContextHandle_HS
     }
 
     void
-    NOTICE_MESSAGE(string fmt, ...)
+    NOTICE_MESSAGE(const char *fmt, ...)
     {
       if (NULL == noticeMessageOld && NULL == noticeMessageNew) {
         return;
@@ -222,7 +222,7 @@ typedef struct GEOSContextHandle_HS
 
       va_list args;
       va_start(args, fmt);
-      int result = vsnprintf(msgBuffer, sizeof(msgBuffer) - 1, fmt.c_str(), args);
+      int result = vsnprintf(msgBuffer, sizeof(msgBuffer) - 1, fmt, args);
       va_end(args);
 
       if (result > 0) {
@@ -235,7 +235,7 @@ typedef struct GEOSContextHandle_HS
     }
 
     void
-    ERROR_MESSAGE(string fmt, ...)
+    ERROR_MESSAGE(const char *fmt, ...)
     {
       if (NULL == errorMessageOld && NULL == errorMessageNew) {
         return;
@@ -243,7 +243,7 @@ typedef struct GEOSContextHandle_HS
 
       va_list args;
       va_start(args, fmt);
-      int result = vsnprintf(msgBuffer, sizeof(msgBuffer) - 1, fmt.c_str(), args);
+      int result = vsnprintf(msgBuffer, sizeof(msgBuffer) - 1, fmt, args);
       va_end(args);
 
       if (result > 0) {
