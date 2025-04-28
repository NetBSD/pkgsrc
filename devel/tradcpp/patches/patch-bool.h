$NetBSD: patch-bool.h,v 1.1 2025/04/28 17:47:53 tnn Exp $

Fix C99 test. (don't redefine bool)

--- bool.h.orig	2025-04-28 17:45:39.254903590 +0000
+++ bool.h
@@ -30,7 +30,7 @@
 #ifndef BOOL_H
 #define BOOL_H
 
-#if __STDC__ > 199901
+#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
 #include <stdbool.h>
 #else
 typedef int bool;
