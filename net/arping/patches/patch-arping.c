$NetBSD: patch-arping.c,v 1.1 2020/07/07 08:48:25 sborrill Exp $

Don't declare variables in a for statement.

--- src/arping.c.orig	2020-07-07 09:38:15.158734218 +0100
+++ src/arping.c	2020-07-07 09:38:49.341138903 +0100
@@ -222,11 +222,12 @@
 static ssize_t
 xgetrandom(void *buf, const size_t buflen, const unsigned int flags)
 {
+        int n;
 #ifdef HAVE_GETRANDOM
         return getrandom(buf, buflen, flags);
 #else
         char* p = buf;
-        for (int n = 0; n < buflen; n++) {
+        for (n = 0; n < buflen; n++) {
                 p[n] = random() & 0xff;
         }
         return buflen;
@@ -236,7 +237,8 @@
 static long int
 xrandom() {
         const int maxtry = 10;
-        for (int c = 0; c < maxtry; c++) {
+        int c;
+        for (c = 0; c < maxtry; c++) {
                 long int ret;
                 const ssize_t rc = xgetrandom(&ret, sizeof(ret), 0);
                 if (rc == -1) {
