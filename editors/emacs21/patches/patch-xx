$NetBSD: patch-xx,v 1.4 2015/02/19 14:18:52 wiz Exp $

--- src/s/netbsd.h.orig	2002-05-31 12:29:02.000000000 -0400
+++ src/s/netbsd.h	2015-02-16 18:13:17.000000000 -0500
@@ -60,9 +60,17 @@
 #endif /* not NO_SHARED_LIBS and not ELF */
 
 #if !defined (NO_SHARED_LIBS) && defined (__ELF__)
+#if defined(HAVE_NETBSD_CRTI)
+#define START_FILES pre-crt0.o /usr/lib/crt0.o /usr/lib/crti.o /usr/lib/crtbegin.o
+#else
 #define START_FILES pre-crt0.o /usr/lib/crt0.o /usr/lib/crtbegin.o
+#endif
 #define UNEXEC unexelf.o
+#if defined(HAVE_NETBSD_CRTN)
+#define LIB_STANDARD -lgcc -lc -lgcc /usr/lib/crtend.o /usr/lib/crtn.o
+#else
 #define LIB_STANDARD -lgcc -lc -lgcc /usr/lib/crtend.o
+#endif
 #undef LIB_GCC
 #define LIB_GCC
 #endif
@@ -123,3 +131,42 @@
 
 #define GC_MARK_STACK	GC_MAKE_GCPROS_NOOPS
 
+/* Use sigprocmask(2) and friends instead of sigblock(2); the man page
+   of sigblock says it is obsolete.  */
+
+#define POSIX_SIGNALS		1
+
+#ifdef HAVE_PTYFS	/* Support ptyfs */
+
+/* How to iterate over PTYs. */
+#define PTY_ITERATION for (i = 0; i < 1; i++)
+
+/* How to get the device name of the control end of a PTY, if non-standard. */
+#define PTY_NAME_SPRINTF /**/
+
+/* How to open a PTY, if non-standard. */
+#define PTY_OPEN  { \
+	fd = posix_openpt(O_RDWR | O_CLOEXEC | O_NOCTTY); \
+	if (fd < 0 && errno == EINVAL) \
+		fd = posix_openpt(O_RDWR | O_NOCTTY); \
+}
+
+/* How to get device name of the tty end of a PTY, if non-standard. */
+#define PTY_TTY_NAME_SPRINTF  { \
+	char *ptyname = NULL; \
+	sigset_t blocked; \
+	\
+	sigemptyset (&blocked); \
+	sigaddset(&blocked, SIGCHLD); \
+	pthread_sigmask(SIG_BLOCK, &blocked, 0); \
+	if (grantpt(fd) != -1 && unlockpt(fd) != -1) \
+		ptyname = ptsname(fd); \
+		pthread_sigmask(SIG_UNBLOCK, &blocked, 0); \
+		if (!ptyname) { \
+			emacs_close(fd); \
+			 return -1; \
+		} \
+	snprintf(pty_name, sizeof(pty_name), "%s", ptyname); \
+}
+
+#endif	/* HAVE_PTYFS */
