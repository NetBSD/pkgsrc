$NetBSD: patch-include_my__global.h,v 1.3 2020/07/07 20:18:20 adam Exp $

Portability: include <bstring.h> if exists.

--- include/my_global.h.orig	2020-03-09 10:37:59.000000000 +0000
+++ include/my_global.h
@@ -130,6 +130,10 @@
 #include <io.h>       /* access(), chmod() */
 #include <process.h>  /* getpid() */
 
+#ifdef NEEDS_BSTRING_H
+#include <bstring.h> /* defines bzero() */
+#endif
+
 #define sleep(a) Sleep((a)*1000)
 
 /* Define missing access() modes. */
@@ -1118,7 +1122,8 @@ typedef char		my_bool; /* Small bool */
 
 /* Provide __func__ macro definition for platforms that miss it. */
 #if __STDC_VERSION__ < 199901L
-#  if __GNUC__ >= 2
+#  if __GNUC__ >= 4
+#  elif __GNUC__ >= 2
 #    define __func__ __FUNCTION__
 #  else
 #    define __func__ "<unknown>"
