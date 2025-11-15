$NetBSD: patch-libass_ass__strtod.c,v 1.1 2025/11/15 12:43:18 ryoon Exp $

--- libass/ass_strtod.c.orig	2025-10-08 03:50:54.720921982 +0000
+++ libass/ass_strtod.c
@@ -99,7 +99,7 @@ ass_strtod(string, endPtr)
      */
 
     p = string;
-    while (isspace(*p)) {
+    while (isspace((unsigned char)(*p))) {
         p += 1;
     }
     if (*p == '-') {
@@ -121,7 +121,7 @@ ass_strtod(string, endPtr)
     for (mantSize = 0; ; mantSize += 1)
     {
         c = *p;
-        if (!isdigit(c)) {
+        if (!isdigit((unsigned char)c)) {
             if ((c != '.') || (decPt >= 0)) {
                 break;
             }
@@ -197,7 +197,7 @@ ass_strtod(string, endPtr)
             }
             expSign = 0;
         }
-        while (isdigit(*p)) {
+        while (isdigit((unsigned char)(*p))) {
             exp = exp * 10 + (*p - '0');
             p += 1;
         }
