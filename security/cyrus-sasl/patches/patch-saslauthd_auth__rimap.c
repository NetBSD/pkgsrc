$NetBSD: patch-saslauthd_auth__rimap.c,v 1.3 2013/09/30 05:44:33 obache Exp $

* Added missing include files for struct timeval
  http://git.cyrusimap.org/cyrus-sasl/commit/?id=f2e77ab1ac01f611d71ae56ff7635a46b930ef8e

--- saslauthd/auth_rimap.c.orig	2012-10-12 14:05:48.000000000 +0000
+++ saslauthd/auth_rimap.c
@@ -75,6 +75,16 @@
 #include <arpa/inet.h>
 #include <signal.h>
 #include <netdb.h>
+#if TIME_WITH_SYS_TIME
+# include <sys/time.h>
+# include <time.h>
+#else
+# if HAVE_SYS_TIME_H
+#  include <sys/time.h>
+# else
+#  include <time.h>
+# endif
+#endif
 
 #include "auth_rimap.h"
 #include "utils.h"
