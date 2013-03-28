$NetBSD: patch-login.c,v 1.1 2013/03/28 21:17:57 joerg Exp $

--- login.c.orig	2013-03-28 20:03:37.000000000 +0000
+++ login.c
@@ -19,6 +19,10 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 
+#ifdef __NetBSD__
+#include <utmpx.h>
+#endif
+
 /* NeXTStep/86 has some byte order problems (Christian Starkjohann) */
 #if defined(NeXT) && defined(__LITTLE_ENDIAN__) && !defined(NEXTSGTTY)
 # define pw_uid pw_short_pad1
