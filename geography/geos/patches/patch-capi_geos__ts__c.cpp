$NetBSD: patch-capi_geos__ts__c.cpp,v 1.3 2020/03/11 12:52:07 gdt Exp $

Passing non-POD types like std::string to variadic functions is UB.
To avoid this, change functions to take const char * rather than
std::string.
  
\todo File a bug upstream

--- capi/geos_ts_c.cpp.orig	2020-03-10 17:19:40.000000000 +0000
+++ capi/geos_ts_c.cpp
@@ -233,7 +233,7 @@ typedef struct GEOSContextHandle_HS {
     }
 
     void
-    NOTICE_MESSAGE(string fmt, ...)
+    NOTICE_MESSAGE(const char *fmt, ...)
     {
         if(NULL == noticeMessageOld && NULL == noticeMessageNew) {
             return;
@@ -241,7 +241,7 @@ typedef struct GEOSContextHandle_HS {
 
         va_list args;
         va_start(args, fmt);
-        int result = vsnprintf(msgBuffer, sizeof(msgBuffer) - 1, fmt.c_str(), args);
+        int result = vsnprintf(msgBuffer, sizeof(msgBuffer) - 1, fmt, args);
         va_end(args);
 
         if(result > 0) {
@@ -255,7 +255,7 @@ typedef struct GEOSContextHandle_HS {
     }
 
     void
-    ERROR_MESSAGE(string fmt, ...)
+    ERROR_MESSAGE(const char *fmt, ...)
     {
         if(NULL == errorMessageOld && NULL == errorMessageNew) {
             return;
@@ -263,7 +263,7 @@ typedef struct GEOSContextHandle_HS {
 
         va_list args;
         va_start(args, fmt);
-        int result = vsnprintf(msgBuffer, sizeof(msgBuffer) - 1, fmt.c_str(), args);
+        int result = vsnprintf(msgBuffer, sizeof(msgBuffer) - 1, fmt, args);
         va_end(args);
 
         if(result > 0) {
