$NetBSD: patch-si_ksi__sign.c,v 1.1 2023/01/16 03:58:09 dholland Exp $

Be more robust about detecting the system's number of signals.

--- si/ksi_sign.c~	2010-04-11 18:30:50.000000000 +0000
+++ si/ksi_sign.c
@@ -45,6 +45,9 @@
 #  include <sys/select.h>
 #endif
 
+#if !defined(_NSIG) && defined(NSIG)
+#define _NSIG NSIG
+#endif
 
 #if defined(WIN32)
 #  define FD_VALID(fd)	((fd) > 0)
