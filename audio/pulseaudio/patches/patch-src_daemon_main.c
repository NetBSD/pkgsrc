$NetBSD: patch-src_daemon_main.c,v 1.2 2015/02/21 23:13:10 ryoon Exp $

Only display Linux-specific warning on Linux.

--- src/daemon/main.c.orig	2015-02-12 14:10:35.000000000 +0000
+++ src/daemon/main.c
@@ -997,10 +997,12 @@ int main(int argc, char *argv[]) {
 
     pa_disable_sigpipe();
 
+#if defined(__linux__)
     if (pa_rtclock_hrtimer())
         pa_log_info("Fresh high-resolution timers available! Bon appetit!");
     else
         pa_log_info("Dude, your kernel stinks! The chef's recommendation today is Linux with high-resolution timers enabled!");
+#endif
 
     if (conf->lock_memory) {
 #if defined(HAVE_SYS_MMAN_H) && !defined(__ANDROID__)
