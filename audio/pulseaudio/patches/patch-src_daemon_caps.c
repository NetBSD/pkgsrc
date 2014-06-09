$NetBSD: patch-src_daemon_caps.c,v 1.1 2014/06/09 13:08:19 ryoon Exp $

Disable warning about capabilities that only makes sense on Linux.

--- src/daemon/caps.c.orig	2014-01-29 19:48:03.000000000 +0000
+++ src/daemon/caps.c
@@ -93,8 +93,10 @@ void pa_drop_caps(void) {
 #error "Don't know how to do capabilities on your system.  Please send a patch."
 #endif /* __linux__ */
 #else /* HAVE_SYS_CAPABILITY_H */
+#if 0
     pa_log_warn("Normally all extra capabilities would be dropped now, but "
                 "that's impossible because PulseAudio was built without "
                 "capabilities support.");
 #endif
+#endif
 }
