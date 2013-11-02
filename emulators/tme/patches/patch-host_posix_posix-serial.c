$NetBSD: patch-host_posix_posix-serial.c,v 1.1 2013/11/02 22:43:29 christos Exp $

If the device filename is just "pty" allocate one dynamically using the
posix functions to avoid bsd'isms (openpty)

--- host/posix/posix-serial.c.orig	2007-08-23 20:57:01.000000000 -0400
+++ host/posix/posix-serial.c	2013-11-02 17:56:20.000000000 -0400
@@ -933,7 +933,27 @@
   }
   if (fd_in < 0) {
     if (strcmp(filename_in, filename_out) == 0) {
-      fd_in = fd_out = open(filename_in, O_RDWR | O_NONBLOCK);
+      if (strcmp(filename_in, "pty") == 0) {
+	fd_in = fd_out = posix_openpt(O_RDWR | O_NONBLOCK);
+	if (fd_in != -1) {
+	  int serrno;
+	  if (grantpt(fd_in) == -1) {
+bad:	     serrno = errno;
+	    (void)close(fd_in);
+	    (void)close(fd_out);
+	    errno = serrno;
+	  } else {
+	    filename_in = filename_out = ptsname(fd_in);
+	    if (filename_in) {
+	      tme_output_append(_output, "Using %s as console\n", filename_in);
+	    } else {
+	      goto bad;
+	    }
+	  }
+	}
+      } else {
+	fd_in = fd_out = open(filename_in, O_RDWR | O_NONBLOCK);
+      }
     }
     else {
       fd_in = open(filename_in, O_RDONLY | O_NONBLOCK);
