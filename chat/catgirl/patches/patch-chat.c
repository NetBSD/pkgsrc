$NetBSD: patch-chat.c,v 1.1 2025/07/25 19:30:09 vins Exp $

Support sig_t on SunOS. 

--- chat.c.orig	2024-03-22 01:38:43.000000000 +0000
+++ chat.c
@@ -50,6 +50,10 @@
 #include <capsicum_helpers.h>
 #endif
 
+#ifdef __sun
+typedef void (*sig_t)();
+#endif
+
 char *readpassphrase(const char *prompt, char *buf, size_t bufsiz, int flags);
 
 #include "chat.h"
