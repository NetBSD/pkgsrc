$NetBSD: patch-libatalk_bstring_bstrlib.c,v 1.2 2024/11/21 22:02:11 hauke Exp $

When a compiler complains about a missing prototype for a libc
function, just inserting one for what you think the interface might be
is probably not a good idea.

See also <https://github.com/mvp/uhubctl/issues/586>

--- libatalk/bstring/bstrlib.c.orig	2024-11-15 06:52:12.000000000 +0000
+++ libatalk/bstring/bstrlib.c
@@ -2913,12 +2913,6 @@ struct genBstrList g;
 #define START_VSNBUFF (256)
 #else
 
-#if defined(__GNUC__) && !defined(__APPLE__)
-/* Something is making gcc complain about this prototype not being here, so
-   I've just gone ahead and put it in. */
-extern int vsnprintf (char *buf, size_t count, const char *format, va_list arg);
-#endif
-
 #define exvsnprintf(r,b,n,f,a) {r = vsnprintf (b,n,f,a);}
 #endif
 #endif
