$NetBSD: patch-src_lib_fcitx-utils_utils.c,v 1.3 2025/12/07 03:00:55 maya Exp $

Illumos has endian.h just like Linux
Fix ctype abuse by casting to unsigned char

--- src/lib/fcitx-utils/utils.c.orig	2017-12-22 18:02:24.000000000 +0000
+++ src/lib/fcitx-utils/utils.c
@@ -56,14 +56,16 @@
 #include <fcntl.h>
 #include <sys/param.h>
 #include <sys/sysctl.h>
+#  if !defined(__NetBSD__)
 #include <sys/user.h>
+#  endif
 #endif
 
 #if defined(__linux__)
 #include <sys/prctl.h>
 #endif
 
-#if defined(__linux__) || defined(__GLIBC__)
+#if defined(__linux__) || defined(__GLIBC__) || defined(__illumos__)
 #include <endian.h>
 #else
 #include <sys/endian.h>
@@ -400,7 +402,7 @@ char* fcitx_utils_trim(const char* s)
 
     s += strspn(s, "\f\n\r\t\v ");
     end = s + (strlen(s) - 1);
-    while (end >= s && isspace(*end))               /* skip trailing space */
+    while (end >= s && isspace((unsigned char)*end))               /* skip trailing space */
         --end;
 
     end++;
