$NetBSD: patch-src_xfpm-pm-helper.c,v 1.1 2018/05/18 17:07:29 youri Exp $

Add NetBSD support.

--- src/xfpm-pm-helper.c.orig	2015-07-14 08:02:18.000000000 +0000
+++ src/xfpm-pm-helper.c
@@ -77,6 +77,10 @@
 #define UP_BACKEND_SUSPEND_COMMAND	"/usr/sbin/zzz"
 #define UP_BACKEND_HIBERNATE_COMMAND "/usr/sbin/ZZZ"
 #endif
+#ifdef BACKEND_TYPE_NETBSD
+#define UP_BACKEND_SUSPEND_COMMAND "sysctl -w hw.acpi.sleep.state=1"
+#define UP_BACKEND_HIBERNATE_COMMAND "sysctl -w hw.acpi.sleep.state=4"
+#endif
 
 
 static gboolean
@@ -174,19 +178,25 @@ main (int argc, char **argv)
   /* run the command */
   if(suspend)
   {
+#if defined(UP_BACKEND_SUSPEND_COMMAND)
     if (run (UP_BACKEND_SUSPEND_COMMAND))
     {
       return EXIT_CODE_SUCCESS;
-    } else {
+    } else
+#endif
+    {
       return EXIT_CODE_FAILED;
     }
   }
   else if (hibernate)
   {
+#if defined(UP_BACKEND_HIBERNATE_COMMAND)
     if(run (UP_BACKEND_HIBERNATE_COMMAND))
     {
       return EXIT_CODE_SUCCESS;
-    } else {
+    } else
+#endif
+    {
       return EXIT_CODE_FAILED;
     }
   }
