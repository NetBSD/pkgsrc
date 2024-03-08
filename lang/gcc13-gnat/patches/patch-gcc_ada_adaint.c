$NetBSD: patch-gcc_ada_adaint.c,v 1.1 2024/03/08 12:02:33 wiz Exp $

NetBSD does not use symbol versioning, which requires some functions
to be preprocessed in C. This patch adds those functions definitions,
not only for NetBSD, but for any other system too.

--- gcc/ada/adaint.c.orig	2021-04-08 13:56:27.725736525 +0200
+++ gcc/ada/adaint.c	2021-10-09 17:27:52.413919872 +0200
@@ -817,7 +817,8 @@
 }
 
 #if defined (_WIN32) || defined (__linux__) || defined (__sun__) \
-  || defined (__FreeBSD__) || defined(__DragonFly__) || defined (__QNX__)
+  || defined (__FreeBSD__) || defined(__DragonFly__) || defined (__QNX__) \
+  || defined (__NetBSD__)
 #define HAS_TARGET_WCHAR_T
 #endif
 
@@ -3544,6 +3545,69 @@
   */
 }
 
+#if defined(__NetBSD__)
+/* It's 2021, and NetBSD still doesn't use symbol versioning in their
+ * libraries.  They mimic this by having header macros rename the function
+ * at compile time.  If we don't wrap the functions, the osinte specification
+ * for NetBSD would need to import e.g. __sigaltstack14 instead of sigaltstack.
+ * By wrapping, new versions won't break gnat.
+ */
+int
+__gnat_sigemptyset (sigset_t *set) {
+   return sigemptyset (set);
+}
+int
+__gnat_sigfillset (sigset_t *set) {
+   return sigfillset (set);
+}
+int
+__gnat_sigaddset (sigset_t *set, int signo) {
+   return sigaddset (set, signo);
+}
+int
+__gnat_sigdelset (sigset_t *set, int signo) {
+   return sigdelset (set, signo);
+}
+int
+__gnat_sigismember (sigset_t *set, int signo) {
+   return sigismember (set, signo);
+}
+int
+__gnat_sigaltstack (const stack_t *ss, stack_t *oss) {
+   return sigaltstack (ss, oss);
+}
+int
+__gnat_sigaction (int sig, const struct sigaction *act, struct sigaction *oact) {
+   return sigaction (sig, act, oact);
+}
+int
+__gnat_clock_getres (clockid_t clock_id, struct timespec *res) {
+   return clock_getres (clock_id, res);
+}
+int
+__gnat_clock_gettime (clockid_t clock_id, struct timespec *tp) {
+   return clock_gettime (clock_id, tp);
+}
+#endif
+int
+__gnat_nanosleep (const struct timespec *rqtp, struct timespec *rmtp) {
+   return nanosleep (rqtp, rmtp);
+}
+int
+__gnat_gettimeofday (struct timeval * tp, struct timezone * tzp) {
+   return gettimeofday (tp, tzp);
+}
+
+int
+__gnat_select(int nfds, fd_set * readfds, fd_set * writefds,
+              fd_set * exceptfds, struct timeval * timeout) {
+   return select (nfds, readfds, writefds, exceptfds, timeout);
+}
+int
+__gnat_socket (int domain, int type, int protocol) {
+   return socket (domain, type, protocol);
+}
+
 #ifdef __cplusplus
 }
 #endif
