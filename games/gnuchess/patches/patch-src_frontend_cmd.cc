$NetBSD: patch-src_frontend_cmd.cc,v 1.1 2026/09/21 09:30:53 wiz Exp $

Fix ctype(3) usage.
Mailed to bug-gnu-chess mailing list on 2026-09-21.

--- src/frontend/cmd.cc.orig	2026-09-21 08:51:06.915496850 +0000
+++ src/frontend/cmd.cc
@@ -69,14 +69,14 @@ static void split_input(void)
 
   for (k = 0, s = r = inputstr; k < TOKENS; ++k) {
     /* Skip leading whitespace */
-    while (isspace(*s)) s++;
+    while (isspace((unsigned char)*s)) s++;
     token[k] = s;
     /* Skip token */
-    while (*s && !isspace(*s)) r = s++;
+    while (*s && !isspace((unsigned char)*s)) r = s++;
   }
   while (*s) {
-    while (isspace(*s)) s++;
-    while (*s && !isspace(*s)) r = s++;
+    while (isspace((unsigned char)*s)) s++;
+    while (*s && !isspace((unsigned char)*s)) r = s++;
   }
   r[1] = '\0';
 }
@@ -87,10 +87,10 @@ static int tokeneq(const char *s, const char *t)
  */
 static int tokeneq(const char *s, const char *t)
 {
-  while (*s && *t && !isspace(*s) && !isspace(*t)) {
+  while (*s && *t && !isspace((unsigned char)*s) && !isspace((unsigned char)*t)) {
     if (*s++ != *t++) return 0;
   }
-  return (!*s || isspace(*s)) && (!*t || isspace(*t));
+  return (!*s || isspace((unsigned char)*s)) && (!*t || isspace((unsigned char)*t));
 }
 
 /*
