$NetBSD: patch-ipc_chromium_src_base_third__party_nspr_prtime.cc,v 1.1.1.1 2012/03/15 08:58:28 ryoon Exp $

--- ipc/chromium/src/base/third_party/nspr/prtime.cc.orig	2012-03-09 22:20:17.000000000 +0000
+++ ipc/chromium/src/base/third_party/nspr/prtime.cc
@@ -212,7 +212,7 @@ PR_ImplodeTime(const PRExplodedTime *exp
     LL_ADD(retVal, retVal, temp);
 
     return retVal;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_DRAGONFLY)
     struct tm exp_tm = {0};
     exp_tm.tm_sec  = exploded->tm_sec;
     exp_tm.tm_min  = exploded->tm_min;
@@ -245,6 +245,24 @@ PR_ImplodeTime(const PRExplodedTime *exp
     result *= kSecondsToMicroseconds;
     result += exploded->tm_usec;
     return result;
+#elif defined(OS_FREEBSD) || defined(OS_NETBSD)
+    struct tm exp_tm = {0};
+    exp_tm.tm_sec  = exploded->tm_sec;
+    exp_tm.tm_min  = exploded->tm_min;
+    exp_tm.tm_hour = exploded->tm_hour;
+    exp_tm.tm_mday = exploded->tm_mday;
+    exp_tm.tm_mon  = exploded->tm_month;
+    exp_tm.tm_year = exploded->tm_year - 1900;
+
+    // time_t is 64bit
+    time_t absolute_time = timegm(&exp_tm);
+
+    PRTime result = static_cast<PRTime>(absolute_time);
+    result -= exploded->tm_params.tp_gmt_offset +
+              exploded->tm_params.tp_dst_offset;
+    result *= kSecondsToMicroseconds;
+    result += exploded->tm_usec;
+    return result;
 #else
 #error No PR_ImplodeTime implemented on your platform.
 #endif
