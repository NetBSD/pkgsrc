$NetBSD: patch-async_aio.C,v 1.1 2017/09/09 19:45:46 dholland Exp $

Clean up %m abuse.

--- async/aio.C~	2009-02-12 13:20:42.000000000 +0000
+++ async/aio.C
@@ -21,6 +21,7 @@
  *
  */
 
+#include <cstring>
 #include "aiod.h"
 
 aiobuf::aiobuf (aiod *d, size_t p, size_t l)
@@ -62,7 +63,7 @@ aiod::writeq::output ()
   wbuf.copyout (buf, wsize);
   ssize_t n = write (wfd, buf, wsize);
   if (n < 0)
-    fatal ("write to aiod failed (%m)\n"); // XXX - should make aiod fail
+    fatal ("write to aiod failed (%s)\n", strerror(errno)); // XXX - should make aiod fail
   wbuf.rembytes (n);
   if (!wbuf.resid ())
     fdcb (wfd, selwrite, NULL);
@@ -81,7 +82,7 @@ aiod::writeq::sendmsg (aiomsg_t msg)
   else {
     ssize_t n = write (wfd, &msg, sizeof (msg));
     if (n < 0)
-      fatal ("write to aiod failed (%m)\n");
+      fatal ("write to aiod failed (%s)\n", strerror(errno));
     if (n != sizeof (msg)) {
       // Writes less than PIPE_BUF were supposed to be atomic
       warn ("aiod::writeq::sendmsg: partial write (%d bytes)\n", (int) n);
@@ -98,7 +99,7 @@ aiod::daemon::launch (str path, int shmf
 
   int fds[2];
   if (socketpair (AF_UNIX, SOCK_STREAM, 0, fds) < 0)
-    fatal ("aiod::daemon::launch: socketpair failed: %m\n");
+    fatal ("aiod::daemon::launch: socketpair failed: %s\n", strerror(errno));
   wq.wfd = fd = fds[0];
   close_on_exec (fd);
 
@@ -166,24 +167,24 @@ aiod::aiod (u_int nproc, ssize_t shmsize
       xfree (temp);
     }
   if (!tmpfile)
-    fatal ("aiod: could not create temporary file: %m\n");
+    fatal ("aiod: could not create temporary file: %s\n", strerror(errno));
   umask (m);
   close_on_exec (shmfd);
   if (ftruncate (shmfd, shmmax) < 0)
-    fatal ("aiod: could not grow shared mem file (%m)\n");
+    fatal ("aiod: could not grow shared mem file (%s)\n", strerror(errno));
   struct stat sb;
   if (fstat (shmfd, &sb) < 0)
-    fatal ("fstat (%s): %m\n", tmpfile.cstr ());
+    fatal ("fstat (%s): %s\n", tmpfile.cstr (), strerror(errno));
 
   shmbuf = static_cast<char *>
     (mmap (NULL, (size_t) shmmax, PROT_READ|PROT_WRITE,
 	   MAP_FILE|MAP_SHARED, shmfd, 0));
   if (shmbuf == (char *) MAP_FAILED)
-    fatal ("aiod: could not mmap shared mem file (%m)\n");
+    fatal ("aiod: could not mmap shared mem file (%s)\n", strerror(errno));
 
   int fds[2];
   if (pipe (fds) < 0)
-    fatal ("aiod: pipe syscall failed: %m\n");
+    fatal ("aiod: pipe syscall failed: %s\n", strerror(errno));
   wq.wfd = fds[1];
   close_on_exec (wq.wfd);
   int rfd = fds[0];
@@ -201,10 +202,10 @@ aiod::aiod (u_int nproc, ssize_t shmsize
      * wherever possible we use flock as it is faster.)  */
     int fd = ::open (tmpfile, O_RDWR);
     if (fd < 0)
-      fatal ("cannot reopen %s: %m\n", tmpfile.cstr ());
+      fatal ("cannot reopen %s: %s\n", tmpfile.cstr (), strerror(errno));
     struct stat sb2;
     if (fstat (fd, &sb2) < 0)
-      fatal ("fstat (%s): %m\n", tmpfile.cstr ());
+      fatal ("fstat (%s): %s\n", tmpfile.cstr (), strerror(errno));
     if (sb.st_dev != sb2.st_dev || sb.st_ino != sb2.st_ino)
       fatal ("aiod: somone tampered with %s\n", tmpfile.cstr ());
 
@@ -223,14 +224,14 @@ aiod::aiod (u_int nproc, ssize_t shmsize
    * consuming disk space to make sure it gets garbage collected
    * properly.  */
   if (::unlink (tmpfile) < 0)
-    fatal ("aiod: unlink (%s): %m\n", tmpfile.cstr ());
+    fatal ("aiod: unlink (%s): %s\n", tmpfile.cstr (), strerror(errno));
 }
 
 aiod::~aiod ()
 {
   fail ();
   if (munmap (shmbuf, shmlen) < 0)
-    warn ("~aiod could not unmap shared mem: %m\n");
+    warn ("~aiod could not unmap shared mem: %s\n", strerror(errno));
   close (shmfd);
   delete[] dv;
 }
@@ -267,7 +268,7 @@ aiod::input (int i)
   ssize_t n = read (dv[i].fd, buf, sizeof (buf));
   if (n <= 0) {
     if (n < 0)
-      warn ("aiod: read: %m\n");
+      warn ("aiod: read: %s\n", strerror(errno));
     else
       warn ("aiod: EOF\n");
     fail ();
@@ -469,7 +470,7 @@ aiod::bufalloc_cb2 (size_t inc, ptr<aiob
     bb.settotsize (shmlen + inc);
     shmlen = bb.gettotsize ();
     if (shmpin && mlock (shmbuf + oshmlen, shmlen - oshmlen) < 0)
-      warn ("could not pin aiod shared memory: %m\n");
+      warn ("could not pin aiod shared memory: %s\n", strerror(errno));
     bufwake ();
   }
 }
