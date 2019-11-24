$NetBSD: patch-lib_holidays.c,v 1.1 2019/11/24 20:16:55 spz Exp $

from https://sourceforge.net/p/xymon/code/8084/
Add guards around GCC diagnostics pragma to allow for building on older vers

--- lib/holidays.c.orig	2019-07-23 14:46:51.000000000 +0000
+++ lib/holidays.c
@@ -596,10 +596,14 @@ void printholidays(char *key, strbuffer_
 			if ((tm.tm_mon >= mfirst) && (tm.tm_mon <= mlast)) {
 				strftime(dstr, sizeof(dstr), fmt, localtime(&t));
 
+#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
 				#pragma GCC diagnostic push
 				#pragma GCC diagnostic ignored "-Wformat-truncation"
+#endif  // __GNUC__
 				snprintf(oneh, sizeof(oneh), "<tr><td>%s</td><td>%s</td>\n", desc, dstr);
+#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
 				#pragma GCC diagnostic pop
+#endif  // __GNUC__
 				addtobuffer(buf, oneh);
 			}
 		}
