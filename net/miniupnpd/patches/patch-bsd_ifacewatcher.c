$NetBSD: patch-bsd_ifacewatcher.c,v 1.1 2013/10/21 10:06:57 fhajny Exp $

use SA_LEN wrapper
--- bsd/ifacewatcher.c.orig	2012-05-21 08:55:10.000000000 +0000
+++ bsd/ifacewatcher.c
@@ -15,12 +15,8 @@
 #include <syslog.h>
 #include <signal.h>
 
-#if !defined(SA_LEN)
-#define	SA_LEN(sa)	(sa)->sa_len
-#endif
-
 #define	SALIGN	(sizeof(long) - 1)
-#define	SA_RLEN(sa)	((sa)->sa_len ? (((sa)->sa_len + SALIGN) & ~SALIGN) : (SALIGN + 1))
+#define	SA_RLEN(sa)	(SA_LEN(sa) ? ((SA_LEN(sa) + SALIGN) & ~SALIGN) : (SALIGN + 1))
 
 #include "../upnputils.h"
 #include "../upnpglobalvars.h"
