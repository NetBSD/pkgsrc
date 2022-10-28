$NetBSD: patch-src_system_Time.c,v 1.1 2022/10/28 18:25:01 he Exp $

Fix one more pair of isxxxx() uses by casting arg to u_char.

--- src/system/Time.c.orig	2020-03-31 22:57:32.000000000 +0000
+++ src/system/Time.c
@@ -290,9 +290,9 @@ yy10:
 	{ // Timezone: +-HH:MM, +-HH or +-HHMM is offset from UTC in seconds
                         if (have_time) { // Only set timezone if we have parsed time
                                 tm.TM_GMTOFF = _a2i(token + 1, 2) * 3600;
-                                if (isdigit(token[3]))
+                                if (isdigit((u_char)token[3]))
                                         tm.TM_GMTOFF += _a2i(token + 3, 2) * 60;
-                                else if (isdigit(token[4]))
+                                else if (isdigit((u_char)token[4]))
                                         tm.TM_GMTOFF += _a2i(token + 4, 2) * 60;
                                 if (token[0] == '-')
                                         tm.TM_GMTOFF *= -1;
