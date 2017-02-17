$NetBSD: patch-lib_cloexec.h,v 1.1 2017/02/17 17:00:30 joerg Exp $

--- lib/cloexec.h.orig	2012-03-26 18:25:19.000000000 +0000
+++ lib/cloexec.h
@@ -45,12 +45,15 @@ static __inline socket_t socket_cloexec(
 
 /* This supports an accept4() equivalent on NetBSD 6 and later */
 #if defined(SOCK_CLOEXEC) && defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Version__ < 799005900
 static __inline int accept4(int s, struct sockaddr * addr, socklen_t *addrlen,
 			    int flags)
 {
      return paccept(s, addr, addrlen, NULL, flags);
 }
 #endif
+#endif
 
 static __inline socket_t accept_cloexec(socket_t sockfd, struct sockaddr *addr,
 				      socklen_t *addrlen)
