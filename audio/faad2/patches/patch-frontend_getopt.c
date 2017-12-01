$NetBSD: patch-frontend_getopt.c,v 1.2 2017/12/01 11:17:51 adam Exp $

Avoid conflicting definitions.

--- frontend/getopt.c.orig	2017-09-06 08:37:30.000000000 +0000
+++ frontend/getopt.c
@@ -171,7 +171,6 @@ static enum
 
 #if __STDC__ || defined(PROTO)
 extern char *getenv(const char *name);
-extern int  strcmp (const char *s1, const char *s2);
 
 static int my_strlen(const char *s);
 static char *my_index (const char *str, int chr);
