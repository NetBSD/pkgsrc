$NetBSD: patch-src_modules_module-detect.c,v 1.7 2021/02/20 22:10:39 ryoon Exp $

Hack to set proper sound device on NetBSD.

--- src/modules/module-detect.c.orig	2019-07-05 00:06:47.000000000 +0000
+++ src/modules/module-detect.c
@@ -121,7 +121,27 @@ static int detect_alsa(pa_core *c, int j
 static int detect_oss(pa_core *c, int just_one) {
     FILE *f;
     int n = 0, b = 0;
+    pa_module *m = NULL;
+
+#if defined(__NetBSD__)
+/*
+ * Use audio and audio0 to audio3 that are enabled by default
+ * under NetBSD.
+ */
+    char args[64];
 
+    pa_snprintf(args, sizeof(args), "mmap=0 device=@DEVOSSAUDIO@");
+    if (pa_module_load(&m, c, "module-oss", args) < 0)
+      return 0;
+
+    for (int i = 0; i < 4; i++) {
+      pa_snprintf(args, sizeof(args), "mmap=0 device=@DEVOSSAUDIO@%d", i);
+      if (pa_module_load(&m, c, "module-oss", args) < 0)
+        return i + 1;
+    }
+
+    n = 5;
+#else /* __linux__ or __FreeBSD__ */
     if (!(f = pa_fopen_cloexec("/dev/sndstat", "r")) &&
         !(f = pa_fopen_cloexec("/proc/sndstat", "r")) &&
         !(f = pa_fopen_cloexec("/proc/asound/oss/sndstat", "r"))) {
@@ -135,7 +155,6 @@ static int detect_oss(pa_core *c, int ju
     while (!feof(f)) {
         char line[256], args[64];
         unsigned device;
-        pa_module *m = NULL;
 
         if (!fgets(line, sizeof(line), f))
             break;
@@ -174,6 +193,7 @@ static int detect_oss(pa_core *c, int ju
     }
 
     fclose(f);
+#endif
     return n;
 }
 #endif
