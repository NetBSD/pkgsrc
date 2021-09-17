$NetBSD: patch-src_utils_Remotery.c,v 1.1 2021/09/17 00:10:21 nia Exp $

Add support for NetBSD.

--- src/utils/Remotery.c.orig	2020-09-10 16:38:49.000000000 +0000
+++ src/utils/Remotery.c
@@ -114,7 +114,7 @@ static rmtBool g_SettingsInitialized = R
         #include <time.h>
         #if defined(__FreeBSD__) || defined(__OpenBSD__)
             #include <pthread_np.h>
-        #else
+        #elif !defined(__NetBSD__)
             #include <sys/prctl.h>
         #endif
     #endif
@@ -5269,6 +5269,8 @@ static void SetDebuggerThreadName(const 
         strncat_s(name_clamp, sizeof(name_clamp), name, 15);
         #if defined(__FreeBSD__) || defined(__OpenBSD__)
             pthread_set_name_np(pthread_self(), name_clamp);
+        #elif defined(__NetBSD__)
+            pthread_setname_np(pthread_self(), "%s", name_clamp);
         #else
             prctl(PR_SET_NAME,name_clamp,0,0,0);
         #endif
