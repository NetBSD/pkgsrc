$NetBSD: patch-stud.c,v 1.1 2013/03/16 19:41:36 jym Exp $

SunOS fixes as per https://github.com/bumptech/stud/pull/71.
--- stud.c.orig	2012-08-15 10:33:39.000000000 +0000
+++ stud.c
@@ -189,9 +189,17 @@ typedef struct proxystate {
 
 /* Set a file descriptor (socket) to non-blocking mode */
 static void setnonblocking(int fd) {
-    int flag = 1;
-
-    assert(ioctl(fd, FIONBIO, &flag) == 0);
+    int flag;
+#if defined(O_NONBLOCK)
+    /* O_NONBLOCK is more portable and POSIX-standard */
+    flag = O_NONBLOCK;
+    assert (fcntl(fd, F_SETFL, flag) == 0);
+#elif defined(FIONBIO)
+    flag = 1;
+    assert (ioctl(fd, FIONBIO, &flag) == 0);
+#else
+# error O_NONBLOCK and FIONBIO are both undefined for this platform
+#endif
 }
 
 /* set a tcp socket to use TCP Keepalive */
@@ -203,9 +211,9 @@ static void settcpkeepalive(int fd) {
         ERR("Error activating SO_KEEPALIVE on client socket: %s", strerror(errno));
     }
 
+#ifdef TCP_KEEPIDLE
     optval = CONFIG->TCP_KEEPALIVE_TIME;
     optlen = sizeof(optval);
-#ifdef TCP_KEEPIDLE
     if(setsockopt(fd, SOL_TCP, TCP_KEEPIDLE, &optval, optlen) < 0) {
         ERR("Error setting TCP_KEEPIDLE on client socket: %s", strerror(errno));
     }
@@ -1751,24 +1759,16 @@ void daemonize () {
         exit(0);
     }
 
-    /* close standard streams */
-    fclose(stdin);
-    fclose(stdout);
-    fclose(stderr);
-
     /* reopen standard streams to null device */
-    stdin = fopen(NULL_DEV, "r");
-    if (stdin == NULL) {
+    if (freopen(NULL_DEV, "r", stdin) == NULL) {
         ERR("Unable to reopen stdin to %s: %s\n", NULL_DEV, strerror(errno));
         exit(1);
     }
-    stdout = fopen(NULL_DEV, "w");
-    if (stdout == NULL) {
+    if (freopen(NULL_DEV, "w", stdout) == NULL) {
         ERR("Unable to reopen stdout to %s: %s\n", NULL_DEV, strerror(errno));
         exit(1);
     }
-    stderr = fopen(NULL_DEV, "w");
-    if (stderr == NULL) {
+    if (freopen(NULL_DEV, "w", stderr) == NULL) {
         ERR("Unable to reopen stderr to %s: %s\n", NULL_DEV, strerror(errno));
         exit(1);
     }
