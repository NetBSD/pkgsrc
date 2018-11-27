$NetBSD: patch-libatalk_bstring_bstrlib.c,v 1.1 2018/11/27 02:19:03 christos Exp $

Fix for SSP build.

--- libatalk/bstring/bstrlib.c.orig	2014-01-10 05:19:29.000000000 -0500
+++ libatalk/bstring/bstrlib.c	2018-11-26 20:23:28.658129721 -0500
@@ -2737,11 +2737,14 @@
 #define START_VSNBUFF (256)
 #else
 
+#ifndef __NetBSD__
+/* Don't redeclare snprintf, it confuses SSP */
 #ifdef __GNUC__
 /* Something is making gcc complain about this prototype not being here, so 
    I've just gone ahead and put it in. */
 extern int vsnprintf (char *buf, size_t count, const char *format, va_list arg);
 #endif
+#endif
 
 #define exvsnprintf(r,b,n,f,a) {r = vsnprintf (b,n,f,a);}
 #endif
