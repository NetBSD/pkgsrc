$NetBSD: patch-src_terminal.c,v 1.3 2025/08/08 07:24:00 adam Exp $

BSD support https://github.com/hashcat/hashcat/pull/4392

--- src/terminal.c.orig	2025-08-01 21:03:55.000000000 +0000
+++ src/terminal.c
@@ -459,7 +459,8 @@ void SetConsoleWindowSize (const int x)
 }
 #endif
 
-#if defined (__FreeBSD__) || defined (__NetBSD__) || defined (__linux__) || defined (__CYGWIN__)
+#if defined (__OpenBSD__)   || (__FreeBSD__)       || defined (__NetBSD__) || \
+    defined (__DragonFly__) || defined (__linux__) || defined (__CYGWIN__)
 static struct termios savemodes;
 static int havemodes = 0;
 
@@ -1325,7 +1326,33 @@ void backend_info (hashcat_ctx_t *hashca
 
     char *hw_model_buf = NULL;
 
-    #if !defined (__linux__) && !defined (__CYGWIN__) && !defined (__MSYS__)
+    #if defined (__OpenBSD__)
+
+    int mib[2] = {CTL_HW, HW_MACHINE};
+
+    size_t hw_model_len = 0;
+
+    // First get length of the result string
+
+    if (sysctl (mib, 2, NULL, &hw_model_len, NULL, 0) == 0 && hw_model_len > 0)
+    {
+      hw_model_buf = (char *) hcmalloc (hw_model_len);
+
+      if (sysctl (mib, 2, hw_model_buf, &hw_model_len, NULL, 0) != 0)
+      {
+        hcfree (hw_model_buf);
+
+        hw_model_buf = NULL;
+
+        hw_model_len = 0;
+      }
+      else
+      {
+        rc_sysctl = true;
+      }
+    }
+
+    #elif !defined (__linux__) && !defined (__CYGWIN__) && !defined (__MSYS__)
 
     size_t hw_model_len = 0;
 
