$NetBSD: patch-lib_util_sig2str.c,v 1.1.2.2 2019/10/15 18:10:37 bsiegert Exp $

Handle sysconf(_SC_RTSIG_MAX) not existing (netbsd):
just assume the static limits is good enough.

--- lib/util/sig2str.c.orig	2019-10-10 16:33:03.000000000 +0000
+++ lib/util/sig2str.c
@@ -65,6 +65,7 @@ sudo_sig2str(int signo, char *signame)
 #if defined(SIGRTMIN) && defined(SIGRTMAX)
     /* Realtime signal support. */
     if (signo >= SIGRTMIN && signo <= SIGRTMAX) {
+#ifdef _SC_RTSIG_MAX
 	const long rtmax = sysconf(_SC_RTSIG_MAX);
 	if (rtmax > 0) {
 	    if (signo == SIGRTMIN) {
@@ -79,6 +80,7 @@ sudo_sig2str(int signo, char *signame)
 		    (SIGRTMAX - signo));
 	    }
 	}
+#endif
 	return 0;
     }
 #endif
