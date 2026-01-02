$NetBSD: patch-src_system_Time.c,v 1.3 2026/01/02 17:50:48 tnn Exp $

Fix uses of isxxxx() by casting arg to u_char.

--- src/system/Time.c.orig	2025-12-31 16:37:52.418416030 +0000
+++ src/system/Time.c
@@ -148,7 +148,7 @@ static inline int _a2i(const char *a, in
 }
 
 static inline int _m2i(const char m[static 3]) {
-        char month[3] = {[0] = tolower(m[0]), [1] = tolower(m[1]), [2] = tolower(m[2])};
+        char month[3] = {[0] = tolower((u_char)m[0]), [1] = tolower((u_char)m[1]), [2] = tolower((u_char)m[2])};
         static char *months = "janfebmaraprmayjunjulaugsepoctnovdec";
         for (int i = 0; i < 34; i += 3) {
                 if (memcmp(months + i, month, 3) == 0)
@@ -312,9 +312,9 @@ yy9:
 	{ // Timezone: +-HH:MM, +-HH or +-HHMM is offset from UTC in seconds
                         if (have_time) { // Only set timezone if we have parsed time
                                 tm.TM_GMTOFF = _a2i(yytoken + 1, 2) * 3600;
-                                if (isdigit(yytoken[3]))
+                                if (isdigit((u_char)yytoken[3]))
                                         tm.TM_GMTOFF += _a2i(yytoken + 3, 2) * 60;
-                                else if (isdigit(yytoken[4]))
+                                else if (isdigit((u_char)yytoken[4]))
                                         tm.TM_GMTOFF += _a2i(yytoken + 4, 2) * 60;
                                 if (yytoken[0] == '-')
                                         tm.TM_GMTOFF *= -1;
