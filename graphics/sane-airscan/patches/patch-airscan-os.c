$NetBSD: patch-airscan-os.c,v 1.1 2020/12/09 12:05:58 ryoon Exp $

* Support NetBSD.

--- airscan-os.c.orig	2020-11-23 19:47:02.000000000 +0000
+++ airscan-os.c
@@ -17,7 +17,7 @@
 #include <unistd.h>
 #include <sys/stat.h>
 
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 #   include <sys/types.h>
 #   include <sys/sysctl.h>
 #endif
@@ -92,6 +92,14 @@ os_progname_init (void)
         return;
     }
     memmove(os_progname_buf, kp.p_comm, KI_MAXCOMLEN);
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
