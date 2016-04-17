$NetBSD: patch-mozilla_js_src_jsdate.cpp,v 1.1 2016/04/17 18:22:21 ryoon Exp $

--- mozilla/js/src/jsdate.cpp.orig	2015-06-08 17:49:25.000000000 +0000
+++ mozilla/js/src/jsdate.cpp
@@ -2669,11 +2669,11 @@ ToLocaleFormatHelper(JSContext* cx, Hand
         if (strcmp(format, "%x") == 0 && result_len >= 6 &&
             /* Format %x means use OS settings, which may have 2-digit yr, so
                hack end of 3/11/22 or 11.03.22 or 11Mar22 to use 4-digit yr...*/
-            !isdigit(buf[result_len - 3]) &&
-            isdigit(buf[result_len - 2]) && isdigit(buf[result_len - 1]) &&
+            !isdigit(((unsigned char)buf[result_len - 3])) &&
+            isdigit(((unsigned char)buf[result_len - 2])) && isdigit(((unsigned char)buf[result_len - 1])) &&
             /* ...but not if starts with 4-digit year, like 2022/3/11. */
-            !(isdigit(buf[0]) && isdigit(buf[1]) &&
-              isdigit(buf[2]) && isdigit(buf[3]))) {
+            !(isdigit(((unsigned char)buf[0])) && isdigit(((unsigned char)buf[1])) &&
+              isdigit(((unsigned char)buf[2])) && isdigit(((unsigned char)buf[3])))) {
             double localtime = obj->as<DateObject>().cachedLocalTime(&cx->runtime()->dateTimeInfo);
             int year = IsNaN(localtime) ? 0 : (int) YearFromTime(localtime);
             JS_snprintf(buf + (result_len - 2), (sizeof buf) - (result_len - 2),
