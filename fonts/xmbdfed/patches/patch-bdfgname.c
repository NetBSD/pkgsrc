$NetBSD: patch-bdfgname.c,v 1.1 2023/09/09 14:56:28 vins Exp $

Prevent conflicting types for getline().

--- bdfgname.c.orig	2004-01-29 17:15:37.000000000 +0000
+++ bdfgname.c
@@ -47,9 +47,9 @@ static unsigned long adobe_names_used;
 
 static int
 #ifdef __STDC__
-getline(FILE *in, char *buf, int limit)
+_bdf_getline(FILE *in, char *buf, int limit)
 #else
-getline(in, buf, limit)
+_bdf_getline(in, buf, limit)
 FILE *in;
 char *buf;
 int limit;
@@ -99,11 +99,11 @@ FILE *in;
 
     while (!feof(in)) {
         pos = ftell(in);
-        (void) getline(in, buf, 256);
+        (void) _bdf_getline(in, buf, 256);
         while (!feof(in) && (buf[0] == 0 || buf[0] == '#')) {
             buf[0] = 0;
             pos = ftell(in);
-            (void) getline(in, buf, 256);
+            (void) _bdf_getline(in, buf, 256);
         }
 
         if (buf[0] == 0)
@@ -170,11 +170,11 @@ FILE *in;
 
     while (!feof(in)) {
         pos = ftell(in);
-        (void) getline(in, buf, 256);
+        (void) _bdf_getline(in, buf, 256);
         while (!feof(in) && (buf[0] == 0 || buf[0] == '#')) {
             buf[0] = 0;
             pos = ftell(in);
-            (void) getline(in, buf, 256);
+            (void) _bdf_getline(in, buf, 256);
         }
 
         c = _bdf_atol(buf, 0, 16);
