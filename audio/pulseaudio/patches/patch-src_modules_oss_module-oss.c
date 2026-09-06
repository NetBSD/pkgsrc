$NetBSD: patch-src_modules_oss_module-oss.c,v 1.5 2026/09/06 14:11:05 tsutsui Exp $

Set DEVOSSAUDIO value to fix default device on NetBSD at least.

Fix excessive OSS playback latency on NetBSD by reapplying the
requested OSS fragment after sample format negotiation.

--- src/modules/oss/module-oss.c.orig	2021-07-27 20:02:27.777868700 +0000
+++ src/modules/oss/module-oss.c
@@ -95,7 +95,7 @@ PA_MODULE_USAGE(
 PA_MODULE_DEPRECATED("Please use module-alsa-card instead of module-oss!");
 #endif
 
-#define DEFAULT_DEVICE "/dev/dsp"
+#define DEFAULT_DEVICE "@DEVOSSAUDIO@"
 
 struct userdata {
     pa_core *core;
@@ -573,6 +573,14 @@ static int unsuspend(struct userdata *u)
         goto fail;
     }
 
+#ifdef __NetBSD__
+    if (u->nfrags >= 2 && u->frag_size >= 1)
+        if (pa_oss_set_fragments(u->fd, u->nfrags, u->orig_frag_size) < 0) {
+            pa_log_warn("Resume failed, couldn't restore fragment settings after format setup.");
+            goto fail;
+        }
+#endif
+
     if (ioctl(u->fd, SNDCTL_DSP_GETBLKSIZE, &frag_size) < 0) {
         pa_log_warn("SNDCTL_DSP_GETBLKSIZE: %s", pa_cstrerror(errno));
         goto fail;
@@ -1266,6 +1274,12 @@ int pa__init(pa_module*m) {
     if (pa_oss_auto_format(fd, &ss) < 0)
         goto fail;
 
+#ifdef __NetBSD__
+    if (nfrags >= 2 && frag_size >= 1)
+        if (pa_oss_set_fragments(fd, nfrags, frag_size) < 0)
+            goto fail;
+#endif
+
     if (ioctl(fd, SNDCTL_DSP_GETBLKSIZE, &frag_size) < 0) {
         pa_log("SNDCTL_DSP_GETBLKSIZE: %s", pa_cstrerror(errno));
         goto fail;
