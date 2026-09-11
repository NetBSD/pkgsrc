$NetBSD: patch-src_contrib_time.c,v 1.1 2026/09/11 12:53:13 drixter Exp $

Patch from upstream to work on SmartOS #980

--- src/contrib/time.c.orig	2026-09-10 16:32:13.079142881 +0000
+++ src/contrib/time.c
@@ -15,6 +15,19 @@
 #include "contrib/ctype.h"
 #include "contrib/string.h"
 
+
+static long get_gmtoff(const struct tm *tm)
+{
+#ifdef __sun
+	return (tm->tm_isdst > 0) ? -altzone : -timezone;
+#else
+	return tm->tm_gmtoff;
+#endif
+}
+
+
+
+
 struct timespec time_now(void)
 {
 	struct timespec result = { 0 };
@@ -422,11 +435,17 @@ int knot_time_print(knot_time_print_t fo
 			return -1;
 		}
 		tt = (time_t)time;
-		ret = (localtime_r(&tt, &lt) == NULL ? -1 :
-		       snprintf_check(dst, dst_len, "%04d-%02d-%02dT%02d:%02d:%02d%+03ld:%02d",
-		                      lt.tm_year + 1900, lt.tm_mon + 1, lt.tm_mday,
-		                      lt.tm_hour, lt.tm_min, lt.tm_sec,
-		                      lt.tm_gmtoff / 3600, abs((int)(lt.tm_gmtoff / 60)) % 60));
+
+		ret = localtime_r(&tt, &lt) == NULL ? -1 : 0;
+		if (ret >= 0) {
+			int gmtoff_min = abs((int)(get_gmtoff(&lt) / 60)) % 60;
+			ret = snprintf_check(dst, dst_len, "%04d-%02d-%02dT%02d:%02d:%02d%+03ld:%02d",
+			                     lt.tm_year + 1900, lt.tm_mon + 1, lt.tm_mday,
+			                     lt.tm_hour, lt.tm_min, lt.tm_sec,
+			                     get_gmtoff(&lt) / 3600, gmtoff_min);
+		}
+
+
 		return (ret > 0 ? 0 : -1);
 	case TIME_PRINT_RELSEC:
 		ret = snprintf(dst, dst_len, "%+"KNOT_TIMEDIFF_PRINTF,
@@ -476,12 +495,12 @@ int knot_time_print_ex(knot_time_print_t
 		tt = (time_t)time;
 		ret = localtime_r(&tt, &lt) == NULL ? -1 : 0;
 		if (ret >= 0) {
-			int gmtoff_min = abs((int)(lt.tm_gmtoff / 60)) % 60;
+			int gmtoff_min = abs((int)(get_gmtoff(&lt) / 60)) % 60;
 			ret = snprintf_check(dst, dst_len, "%04d-%02d-%02dT%02d:%02d:%02d.%03ld%+03ld:%02d%s",
 			                     lt.tm_year + 1900, lt.tm_mon + 1, lt.tm_mday,
 			                     lt.tm_hour, lt.tm_min, lt.tm_sec, millis,
-			                     lt.tm_gmtoff / 3600, gmtoff_min, suffix);
-		}
+					      get_gmtoff(&lt) / 3600, gmtoff_min, suffix);
+	        }
 		return (ret > 0 ? 0 : -1);
 	case TIME_PRINT_RELSEC:
 		;
