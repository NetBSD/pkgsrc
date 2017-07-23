$NetBSD: patch-frontend_getopt.c,v 1.1 2017/07/23 16:09:17 adam Exp $

Avoid conflicting definitions.

--- frontend/getopt.c.orig	2017-07-23 13:10:42.000000000 +0000
+++ frontend/getopt.c
@@ -171,8 +171,6 @@ static enum
 
 #if __STDC__ || defined(PROTO)
 extern char *getenv(const char *name);
-extern int  strcmp (const char *s1, const char *s2);
-extern int  strncmp(const char *s1, const char *s2, unsigned int n);
 
 static int my_strlen(const char *s);
 static char *my_index (const char *str, int chr);
