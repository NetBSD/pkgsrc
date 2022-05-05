$NetBSD: patch-ping.c,v 1.1 2022/05/05 14:31:35 nia Exp $

Horrible hack: NetBSD has gethostbyname_r in libc but it doesn't
actually work.

--- ping.c.orig	2019-02-24 14:53:23.000000000 +0000
+++ ping.c
@@ -34,6 +34,12 @@
 #include "common.h"
 #include "spine.h"
 
+#ifdef __NetBSD__
+#undef HAVE_GETHOSTBYNAME_R_GLIBC
+#undef HAVE_GETHOSTBYNAME_R_SOLARIS
+#undef HAVE_GETHOSTBYNAME_R_HPUX
+#endif
+
 /*! \fn int ping_host(host_t *host, ping_t *ping)
  *  \brief ping a host to determine if it is reachable for polling
  *  \param host a pointer to the current host structure
