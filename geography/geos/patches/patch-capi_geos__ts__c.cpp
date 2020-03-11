$NetBSD: patch-capi_geos__ts__c.cpp,v 1.6 2020/03/11 23:09:09 gdt Exp $

The geos code passes an object of type std::string to variadic functions
NOTICE_MESSAGE and ERROR_MESSAGE, which then pass them to va_start.
Use of non-POD types with varargs is "conditionally supported", which
without a fixed compiler becomes UB.

To avoid this, change the functions to take const char * rather than
std::string (and adjust the use of the variables in the functions).

https://trac.osgeo.org/geos/ticket/1021

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
