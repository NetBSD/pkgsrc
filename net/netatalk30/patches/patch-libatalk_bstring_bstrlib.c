$NetBSD: patch-libatalk_bstring_bstrlib.c,v 1.1 2017/07/14 13:08:31 hauke Exp $

When a compiler complains about a missing prototype for a libc
function, just inserting one for what you think the interface might be
is probably not a good idea.

--- libatalk/bstring/bstrlib.c.orig	2013-03-05 06:24:48.000000000 +0000
+++ libatalk/bstring/bstrlib.c
@@ -2736,13 +2736,6 @@ struct genBstrList g;
 #define exvsnprintf(r,b,n,f,a) {vsprintf (b,f,a); r = -1;}
 #define START_VSNBUFF (256)
 #else
-
-#ifdef __GNUC__
-/* Something is making gcc complain about this prototype not being here, so 
-   I've just gone ahead and put it in. */
-extern int vsnprintf (char *buf, size_t count, const char *format, va_list arg);
-#endif
-
 #define exvsnprintf(r,b,n,f,a) {r = vsnprintf (b,n,f,a);}
 #endif
 #endif
