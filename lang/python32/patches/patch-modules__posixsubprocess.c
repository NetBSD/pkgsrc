$NetBSD: patch-modules__posixsubprocess.c,v 1.1 2013/01/09 17:01:02 reed Exp $

http://bugs.python.org/issue14359
http://hg.python.org/cpython/rev/09371e2ae84d

--- Modules/_posixsubprocess.c
+++ Modules/_posixsubprocess.c
@@ -202,7 +202,18 @@ static void
     int fd_dir_fd;
     if (start_fd >= end_fd)
         return;
-        fd_dir_fd = open(FD_DIR, O_RDONLY | O_CLOEXEC, 0);
+#ifdef O_CLOEXEC
+    fd_dir_fd = open(FD_DIR, O_RDONLY | O_CLOEXEC, 0);
+#else
+    fd_dir_fd = open(FD_DIR, O_RDONLY, 0);
+#ifdef FD_CLOEXEC
+    {
+        int old = fcntl(fd_dir_fd, F_GETFD);
+        if (old != -1)
+            fcntl(fd_dir_fd, F_SETFD, old | FD_CLOEXEC);
+    }
+#endif
+#endif
     if (fd_dir_fd == -1) {
         /* No way to get a list of open fds. */
         _close_fds_by_brute_force(start_fd, end_fd, py_fds_to_keep);

