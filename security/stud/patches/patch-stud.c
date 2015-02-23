$NetBSD: patch-stud.c,v 1.3 2015/02/23 22:27:37 fhajny Exp $

SunOS fixes as per https://github.com/bumptech/stud/pull/71.
SSL fixes as per https://github.com/bumptech/stud/pull/130.
Fix for POSIX accept() that can also return ECONNABORTED.

--- stud.c.orig	2012-08-10 23:40:19.000000000 +0000
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
@@ -889,6 +897,13 @@ static void shutdown_proxy(proxystate *p
         close(ps->fd_up);
         close(ps->fd_down);
 
+        // Clear the SSL error queue - it might contain details
+        // of errors that we haven't consumed for whatever reason.
+        // If we don't, future calls to SSL_get_error will lead to 
+        // weird/confusing results that can throw off the handling
+        // of normal conditions like SSL_ERROR_WANT_READ.
+        ERR_clear_error();
+
         SSL_set_shutdown(ps->ssl, SSL_SENT_SHUTDOWN);
         SSL_free(ps->ssl);
 
@@ -1197,7 +1212,15 @@ static void client_handshake(struct ev_l
             shutdown_proxy(ps, SHUTDOWN_SSL);
         }
         else {
-            LOG("{%s} Unexpected SSL error (in handshake): %d\n", w->fd == ps->fd_up ? "client" : "backend", err);
+
+            // Try and get more detail on the error from the SSL
+            // error queue. ERR_error_string requires a char buffer
+            // of 120 bytes.
+            unsigned long err_detail = ERR_get_error();
+            char err_msg[120];
+            ERR_error_string(err_detail, err_msg);
+
+            LOG("{client} Unexpected SSL error (in handshake): %d, %s\n", err, err_msg);
             shutdown_proxy(ps, SHUTDOWN_SSL);
         }
     }
@@ -1312,7 +1335,7 @@ static void handle_accept(struct ev_loop
             break;
 
         default:
-            assert(errno == EINTR || errno == EWOULDBLOCK || errno == EAGAIN);
+            assert(errno == EINTR || errno == EWOULDBLOCK || errno == EAGAIN || errno == ECONNABORTED);
             break;
         }
         return;
@@ -1751,24 +1774,16 @@ void daemonize () {
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
