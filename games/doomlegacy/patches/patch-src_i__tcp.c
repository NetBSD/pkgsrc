$NetBSD: patch-src_i__tcp.c,v 1.3 2020/06/18 10:14:54 micha Exp $

Use native inet_aton() on Solaris.
Use portable fcntl() instead of ioctl() for non-blocking mode by default.

--- src/i_tcp.c.orig	2020-05-10 22:05:16.000000000 +0000
+++ src/i_tcp.c
@@ -123,7 +123,7 @@
 
 #ifdef __OS2__
   // sys/types.h is also included unconditionally by doomincl.h
-# include <sys/types.h>
+# include <sys/types.h>  // [MB] 2020-06-18: Maybe required for old Unix too
 # include <sys/time.h>
 #endif // __OS2__
 
@@ -146,6 +146,7 @@
 // non-windows includes
 #include <sys/socket.h>
 #include <netinet/in.h>
+#include <fcntl.h>       // [MB] 2020-06-18: For fcntl()
 #include <unistd.h>
 #include <netdb.h>
 #include <sys/ioctl.h>
@@ -355,7 +356,9 @@ byte  generic_hashaddr( mysockaddr_t *a 
 // htons: host to net byte order
 // ntohs: net to host byte order
 
-#if defined( WIN32) || defined( __OS2__) || defined( SOLARIS)
+// [MB] 2020-06-18: Use native inet_aton() on Solaris
+// Solaris has inet_aton() in libresolv since version 2.6 from 1997
+#if defined( WIN32) || defined( __OS2__) // || defined( SOLARIS)
 // [WDJ] Also defined in mserv.c, but too small, will be inlined anyway.
 static inline
 int inet_aton(const char *hostname,
@@ -1006,7 +1009,20 @@ retry_bind:
     CONS_Printf("Network port: %d\n", my_sock_port);
 
     // make it non blocking
+#ifndef LINUX
     ioctl (s, FIONBIO, &trueval);
+#else
+    // [MB] 2020-06-18: Use portable POSIX way to enable non-blocking mode
+    // https://pubs.opengroup.org/onlinepubs/9699919799/functions/fcntl.html
+    {
+        int res = fcntl(s, F_SETFL, O_NONBLOCK);
+        if(-1 == res)
+        {
+            I_SoftError("UDP_Socket: Switching to non-blocking mode failed: %s\n", strerror(errno));
+            goto close_socket;
+        }
+    }
+#endif
 
     // make it broadcastable
 #ifdef LINUX
