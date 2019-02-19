$NetBSD: patch-hotspot_src_os_bsd_vm_jsig.c,v 1.1 2019/02/19 17:00:17 ryoon Exp $

On NetBSD, __sigaction14 should be used as sigaction.

--- hotspot/src/os/bsd/vm/jsig.c.orig	2015-11-03 06:24:48.000000000 +0000
+++ hotspot/src/os/bsd/vm/jsig.c	2019-02-19 03:17:22.275103947 +0000
@@ -171,7 +171,11 @@
 static int call_os_sigaction(int sig, const struct sigaction  *act,
                              struct sigaction *oact) {
   if (os_sigaction == NULL) {
+#if defined(__NetBSD__)
+    os_sigaction = (sigaction_t)dlsym(RTLD_NEXT, "__sigaction14");
+#else
     os_sigaction = (sigaction_t)dlsym(RTLD_NEXT, "sigaction");
+#endif
     if (os_sigaction == NULL) {
       printf("%s\n", dlerror());
       exit(0);
