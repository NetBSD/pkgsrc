$NetBSD: patch-src-s-bsd--common.h,v 1.1 2012/11/26 16:56:16 martin Exp $

# make NetBSD use openpty(), like MacOS

--- src/s/bsd-common.h.orig	2012-11-14 22:04:22.000000000 +0100
+++ src/s/bsd-common.h	2012-11-14 22:23:22.000000000 +0100
@@ -59,6 +59,21 @@
 
 /* Define HAVE_PTYS if the system supports pty devices.  */
 #define HAVE_PTYS
+/* Run only once.  We need a `for'-loop because the code uses `continue'.  */
+#define PTY_ITERATION	int i; for (i = 0; i < 1; i++)
+#define PTY_NAME_SPRINTF	/* none */
+#define PTY_TTY_NAME_SPRINTF	/* none */
+
+#define PTY_OPEN						\
+  do								\
+    {								\
+      int slave;						\
+      if (openpty (&fd, &slave, pty_name, NULL, NULL) == -1)	\
+	fd = -1;						\
+      else							\
+	emacs_close (slave);					\
+    }								\
+  while (0)
 
 /* Define HAVE_SOCKETS if system supports 4.2-compatible sockets.  */
 #define HAVE_SOCKETS

