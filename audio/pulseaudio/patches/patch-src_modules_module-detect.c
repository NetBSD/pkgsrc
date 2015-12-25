$NetBSD: patch-src_modules_module-detect.c,v 1.3 2015/12/25 23:09:49 ryoon Exp $

Hack to set proper sound device on NetBSD.

--- src/modules/module-detect.c.orig	2015-09-10 04:51:41.000000000 +0000
+++ src/modules/module-detect.c
@@ -120,6 +120,17 @@ static int detect_oss(pa_core *c, int ju
     FILE *f;
     int n = 0, b = 0;
 
+#if defined(__NetBSD__)
+/*
+ * Assume primary sound device is used (/dev/audio).
+ * And only primary sound device will be used (n=1).
+ */
+    char args[64];
+    pa_snprintf(args, sizeof(args), "mmap=0 device=/dev/audio");
+    if (!pa_module_load(c, "module-oss", args))
+	exit(1);
+    n = 1;
+#else /* __linux__ or __FreeBSD__ */
     if (!(f = pa_fopen_cloexec("/dev/sndstat", "r")) &&
         !(f = pa_fopen_cloexec("/proc/sndstat", "r")) &&
         !(f = pa_fopen_cloexec("/proc/asound/oss/sndstat", "r"))) {
@@ -171,6 +182,7 @@ static int detect_oss(pa_core *c, int ju
     }
 
     fclose(f);
+#endif
     return n;
 }
 #endif
