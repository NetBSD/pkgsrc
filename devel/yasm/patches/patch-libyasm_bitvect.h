$NetBSD: patch-libyasm_bitvect.h,v 1.1 2025/04/28 19:27:15 tnn Exp $

Don't conflict with C23 true & false.

--- libyasm/bitvect.h.orig	2025-04-28 19:23:19.961028509 +0000
+++ libyasm/bitvect.h
@@ -82,6 +82,9 @@ typedef  Z_longword         *Z_longwordp
 #else
     #ifdef MACOS_TRADITIONAL
         #define boolean Boolean
+    #elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
+        #include <stdbool.h>
+        typedef bool boolean;
     #else
         typedef enum boolean { false = FALSE, true = TRUE } boolean;
     #endif
