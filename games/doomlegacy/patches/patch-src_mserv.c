$NetBSD: patch-src_mserv.c,v 1.2 2020/06/17 16:16:57 micha Exp $

Use native inet_aton() on Solaris.
Use portable fcntl() instead of ioctl() for non-blocking mode by default.

--- src/mserv.c.orig	2020-06-16 09:17:35.000000000 +0000
+++ src/mserv.c
@@ -122,12 +122,13 @@
 #else
 # include <unistd.h>
 # ifdef __OS2__
-#  include <sys/types.h>
+#  include <sys/types.h>  // [MB] 2020-06-16: Maybe required for old Unix too
 # endif
 # include <sys/socket.h>  // socket(),...
 # include <sys/time.h>    // timeval,... (TIMEOUT)
 # include <netinet/in.h>  // sockaddr_in
 # include <arpa/inet.h>   // inet_addr(),...
+# include <fcntl.h>       // [MB] 2020-06-16: For fcntl()
 # include <netdb.h>       // gethostbyname(),...
 # include <sys/ioctl.h>
 # include <errno.h>
@@ -210,7 +211,9 @@ struct Copy_CVarMS_t
 #define close closesocket
 #endif
 
-#if defined( WIN32) || defined( __OS2__) || defined( SOLARIS)
+// [MB] 2020-06-16: Use native inet_aton() on Solaris
+// Solaris has inet_aton() in libresolv since version 2.6 from 1997
+#if defined( WIN32) || defined( __OS2__) // || defined( SOLARIS)
 // it seems windows doesn't define that... maybe some other OS? OS/2
 static inline
 int inet_aton(const char *hostname,
@@ -643,9 +646,19 @@ static int MS_Connect(char *ip_addr, cha
         // winsock.h:  int ioctlsocket(SOCKET,long,u_long *);
         u_long test = 1; // [smite] I have no idea what this type is supposed to be
         ioctlsocket(ms_socket_fd, FIONBIO, &test);
-#else
+#elif defined(__OS2__)
         res = 1;  // non-blocking true
         ioctl(ms_socket_fd, FIONBIO, &res);
+#else
+        // [MB] 2020-06-16: Use portable POSIX way to enable non-blocking mode
+        // https://pubs.opengroup.org/onlinepubs/9699919799/functions/fcntl.html
+        res = fcntl(ms_socket_fd, F_SETFL, O_NONBLOCK);
+        if(-1 == res)
+        {
+            con_state = MSCS_FAILED;
+            MS_Close_socket();
+            return MS_CONNECT_ERROR;
+        }
 #endif
         res = connect(ms_socket_fd, (struct sockaddr *) &ms_addr, sizeof(ms_addr));
         if (res < 0)
