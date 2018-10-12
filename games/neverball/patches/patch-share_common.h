$NetBSD: patch-share_common.h,v 1.1 2018/10/12 09:37:25 leot Exp $

C99 is already passed via CFLAGS and vsnprintf(3) is part of it.

--- share/common.h.orig	2014-05-21 13:21:43.000000000 +0000
+++ share/common.h
@@ -81,15 +81,6 @@ char *concat_string(const char *first, .
 #define str_starts_with(s, h) (strncmp((s), (h), strlen(h)) == 0)
 #define str_ends_with(s, t) ((strlen(s) >= strlen(t)) && strcmp((s) + strlen(s) - strlen(t), (t)) == 0)
 
-/*
- * Declaring vsnprintf with the C99 signature, even though we're
- * claiming to be ANSI C. This is probably bad but is not known to not
- * work.
- */
-#ifndef __APPLE__
-extern int vsnprintf(char *, size_t, const char *, va_list);
-#endif
-
 /* Time. */
 
 time_t make_time_from_utc(struct tm *);
