$NetBSD: patch-src_system_Time.c,v 1.2 2022/10/28 18:39:25 he Exp $

Fix uses of isxxxx() by casting arg to u_char.

--- src/system/Time.c.orig	2020-03-31 22:57:32.000000000 +0000
+++ src/system/Time.c
@@ -147,7 +147,7 @@ static inline int _a2i(const char *a, in
 }
 
 static inline int _m2i(const char m[static 3]) {
-        char month[3] = {[0] = tolower(m[0]), [1] = tolower(m[1]), [2] = tolower(m[2])};
+        char month[3] = {[0] = tolower((u_char)m[0]), [1] = tolower((u_char)m[1]), [2] = tolower((u_char)m[2])};
         static char *months = "janfebmaraprmayjunjulaugsepoctnovdec";
         for (int i = 0; i < 34; i += 3) {
                 if (memcmp(months + i, month, 3) == 0)
@@ -318,9 +318,9 @@ yy9:
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
