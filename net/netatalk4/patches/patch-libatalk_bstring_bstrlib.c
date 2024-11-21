$NetBSD: patch-libatalk_bstring_bstrlib.c,v 1.1 2024/11/21 15:26:08 hauke Exp $

See https://github.com/mvp/uhubctl/issues/586

Maybe the re-definition should just be removed, given the vague
reasoning

--- libatalk/bstring/bstrlib.c.orig	2024-11-08 16:22:48.888569855 +0000
+++ libatalk/bstring/bstrlib.c
@@ -2913,7 +2913,7 @@ struct genBstrList g;
 #define START_VSNBUFF (256)
 #else
 
-#if defined(__GNUC__) && !defined(__APPLE__)
+#if defined(__GNUC__) && !defined(__APPLE__) && !defined(__NetBSD__)
 /* Something is making gcc complain about this prototype not being here, so
    I've just gone ahead and put it in. */
 extern int vsnprintf (char *buf, size_t count, const char *format, va_list arg);
