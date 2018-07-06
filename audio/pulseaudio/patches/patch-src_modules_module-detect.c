$NetBSD: patch-src_modules_module-detect.c,v 1.5 2018/07/06 14:10:15 ryoon Exp $

Hack to set proper sound device on NetBSD.

--- src/modules/module-detect.c.orig	2018-05-11 11:43:30.000000000 +0000
+++ src/modules/module-detect.c
@@ -121,7 +121,19 @@ static int detect_alsa(pa_core *c, int j
 static int detect_oss(pa_core *c, int just_one) {
     FILE *f;
     int n = 0, b = 0;
+    pa_module *m = NULL;
 
+#if defined(__NetBSD__)
+/*
+ * Assume primary sound device is used (/dev/audio).
+ * And only primary sound device will be used (n=1).
+ */
+    char args[64];
+    pa_snprintf(args, sizeof(args), "mmap=0 device=/dev/audio");
+    if (pa_module_load(&m, c, "module-oss", args) < 0)
+	return 0;
+    n = 1;
+#else /* __linux__ or __FreeBSD__ */
     if (!(f = pa_fopen_cloexec("/dev/sndstat", "r")) &&
         !(f = pa_fopen_cloexec("/proc/sndstat", "r")) &&
         !(f = pa_fopen_cloexec("/proc/asound/oss/sndstat", "r"))) {
@@ -135,7 +147,6 @@ static int detect_oss(pa_core *c, int ju
     while (!feof(f)) {
         char line[256], args[64];
         unsigned device;
-        pa_module *m = NULL;
 
         if (!fgets(line, sizeof(line), f))
             break;
@@ -174,6 +185,7 @@ static int detect_oss(pa_core *c, int ju
     }
 
     fclose(f);
+#endif
     return n;
 }
 #endif
