$NetBSD: patch-src_hotspot_os_posix_signals__posix.cpp,v 1.1 2022/05/13 14:24:19 ryoon Exp $

--- src/hotspot/os/posix/signals_posix.cpp.orig	2022-02-05 03:44:09.000000000 +0000
+++ src/hotspot/os/posix/signals_posix.cpp
@@ -816,7 +816,11 @@ static void check_signal_handler(int sig
   static os_sigaction_t os_sigaction = NULL;
   if (os_sigaction == NULL) {
     // only trust the default sigaction, in case it has been interposed
+#if defined(__NetBSD__)
+    os_sigaction = (os_sigaction_t)dlsym(RTLD_DEFAULT, "__sigaction14");
+#else
     os_sigaction = (os_sigaction_t)dlsym(RTLD_DEFAULT, "sigaction");
+#endif
     if (os_sigaction == NULL) return;
   }
 
