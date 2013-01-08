$NetBSD: patch-client.c,v 1.1 2013/01/08 12:36:07 jperkin Exp $

Add Solaris compatability.

--- client.c.orig	2012-10-11 16:51:06.000000000 +0000
+++ client.c	2013-01-08 12:21:54.006769094 +0000
@@ -74,16 +74,32 @@
 client_get_lock(char *lockfile)
 {
 	int lockfd;
+#ifdef __sun
+	struct flock lock;
+	lock.l_type= F_WRLCK;
+	lock.l_whence= SEEK_SET;
+	lock.l_start= 0;
+	lock.l_len= 0;
+#endif
 
 	if ((lockfd = open(lockfile, O_WRONLY|O_CREAT, 0600)) == -1)
 		fatal("open failed");
 
+#ifdef __sun
+	if (fcntl(lockfd, F_SETLK, &lock) == -1) {
+		while (fcntl(lockfd, F_SETLKW, &lock) == -1 && errno == EINTR)
+			/* nothing */;
+		close(lockfd);
+		return(-1);
+	}
+#else
 	if (flock(lockfd, LOCK_EX|LOCK_NB) == -1 && errno == EWOULDBLOCK) {
 		while (flock(lockfd, LOCK_EX) == -1 && errno == EINTR)
 			/* nothing */;
 		close(lockfd);
 		return (-1);
 	}
+#endif
 
 	return (lockfd);
 }
@@ -243,7 +259,15 @@
 			    strerror(errno));
 			return (1);
 		}
+#ifdef __sun
+		tio.c_iflag &= ~(IMAXBEL|IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON);
+		tio.c_oflag &= ~OPOST;
+		tio.c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
+		tio.c_cflag &= ~(CSIZE|PARENB);
+		tio.c_cflag |= CS8;
+#else
 		cfmakeraw(&tio);
+#endif
 		tio.c_iflag = ICRNL|IXANY;
 		tio.c_oflag = OPOST|ONLCR;
 #ifdef NOKERNINFO
