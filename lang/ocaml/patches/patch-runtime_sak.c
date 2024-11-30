$NetBSD: patch-runtime_sak.c,v 1.2 2024/11/30 01:10:52 dholland Exp $

Fix ctype abuse.

--- runtime/sak.c.orig	2024-03-14 16:57:52.000000000 +0000
+++ runtime/sak.c
@@ -34,7 +34,8 @@
 #define printf_os wprintf
 #else
 #define strncmp_os strncmp
-#define toupper_os toupper
+/* Caution: this will not work correctly if passed EOF, but we don't do that */
+#define toupper_os(x) toupper((unsigned char)(x))
 #define printf_os printf
 #endif
 
