$NetBSD: patch-src_daemon_main.c,v 1.1 2014/06/09 13:08:19 ryoon Exp $

Only display Linux-specific warning on Linux.

--- src/daemon/main.c.orig	2014-02-25 14:01:58.000000000 +0000
+++ src/daemon/main.c
@@ -1002,10 +1002,12 @@ int main(int argc, char *argv[]) {
 
     pa_disable_sigpipe();
 
+#if defined(__linux__)
     if (pa_rtclock_hrtimer())
         pa_log_info(_("Fresh high-resolution timers available! Bon appetit!"));
     else
         pa_log_info(_("Dude, your kernel stinks! The chef's recommendation today is Linux with high-resolution timers enabled!"));
+#endif
 
     if (conf->lock_memory) {
 #if defined(HAVE_SYS_MMAN_H) && !defined(__ANDROID__)
