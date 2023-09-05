$NetBSD: patch-airscan-os.c,v 1.2 2023/09/05 14:42:18 ryoon Exp $

* Support NetBSD.

--- airscan-os.c.orig	2021-10-04 18:36:05.000000000 +0000
+++ airscan-os.c
@@ -17,7 +17,7 @@
 #include <unistd.h>
 #include <sys/stat.h>
 
-#if defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #   include <sys/types.h>
 #   include <sys/sysctl.h>
 #endif
@@ -101,6 +101,14 @@ os_progname_init (void)
     if (rc < 0) {
         os_progname_buf[0] = '\0'; /* Just a paranoia */
     }
+#elif defined(__NetBSD__)
+    struct kinfo_proc2 kp;
+    int mib[] = {CTL_KERN, KERN_PROC2, KERN_PROC_PID, getpid(), sizeof(kp), 1};
+    size_t len = sizeof(kp);
+    int rc = sysctl(mib, 6, &kp, &len, NULL, 0);
+    if (rc == -1) {
+      return;
+    }
 #else
     /* This is nice to have but not critical. The caller already has
        to handle os_progname returning NULL. The error is left as a
