$NetBSD: patch-lib_util_str2sig.c,v 1.1 2019/10/14 20:05:58 maya Exp $

Handle sysconf(_SC_RTSIG_MAX) not existing (netbsd):
just assume the static limits is good enough.

--- lib/util/str2sig.c.orig	2019-10-10 16:33:03.000000000 +0000
+++ lib/util/str2sig.c
@@ -112,7 +112,11 @@ sudo_str2sig(const char *signame, int *r
 	}
 	if (signame[5] == '+') {
 	    if (isdigit((unsigned char)signame[6])) {
+#ifdef _SC_RTSIG_MAX
 		const long rtmax = sysconf(_SC_RTSIG_MAX);
+#else
+		const long rtmax = SIGRTMAX;
+#endif
 		const int off = signame[6] - '0';
 
 		if (rtmax > 0 && off < rtmax / 2) {
@@ -131,7 +135,11 @@ sudo_str2sig(const char *signame, int *r
 	}
 	if (signame[5] == '-') {
 	    if (isdigit((unsigned char)signame[6])) {
+#ifdef _SC_RTSIG_MAX
 		const long rtmax = sysconf(_SC_RTSIG_MAX);
+#else
+		const long rtmax = SIGRTMAX;
+#endif
 		const int off = signame[6] - '0';
 
 		if (rtmax > 0 && off < rtmax / 2) {
