$NetBSD: patch-examples_loadables_getconf.c,v 1.1 2022/10/04 12:45:31 kim Exp $

Handle _SC_RTSIG_MAX not being defined (NetBSD 9)

--- examples/loadables/getconf.c.orig	2021-12-03 16:46:22.000000000 +0000
+++ examples/loadables/getconf.c	2022-10-04 12:38:07.370372821 +0000
@@ -846,7 +846,9 @@
 #ifdef _SC_TRACE_LOG
     { "_POSIX_TRACE_LOG", _SC_TRACE_LOG, SYSCONF },
 #endif
+#ifdef _SC_RTSIG_MAX
     { "RTSIG_MAX", _SC_RTSIG_MAX, SYSCONF },
+#endif
 #ifdef _SC_SEM_NSEMS_MAX
     { "SEM_NSEMS_MAX", _SC_SEM_NSEMS_MAX, SYSCONF },
 #endif
