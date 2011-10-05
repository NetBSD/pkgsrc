$NetBSD: patch-extra_pd~_pd~.c,v 1.2 2011/10/05 20:02:48 wiz Exp $

Add missing include (for SIGPIPE).
Define extensions for NetBSD.
https://sourceforge.net/tracker/?func=detail&aid=3411732&group_id=55736&atid=478072

--- extra/pd~/pd~.c.orig	2010-07-28 20:55:17.000000000 +0000
+++ extra/pd~/pd~.c
@@ -6,6 +6,7 @@
 */
 
 #include <stdio.h>
+#include <signal.h>
 #include <string.h>
 #include <unistd.h>
 #include <stdlib.h>
@@ -56,6 +57,15 @@ static char pd_tilde_dllextent[] = ".l_i
     pd_tilde_dllextent2[] = ".pd_linux";
 #endif
 #endif
+#if defined(__NetBSD__)
+#ifdef __x86_64__
+static char pd_tilde_dllextent[] = ".n_ia64",
+    pd_tilde_dllextent2[] = ".pd_netbsd";
+#else
+static char pd_tilde_dllextent[] = ".n_i386",
+    pd_tilde_dllextent2[] = ".pd_netbsd";
+#endif
+#endif
 #ifdef __APPLE__
 static char pd_tilde_dllextent[] = ".d_fat",
     pd_tilde_dllextent2[] = ".pd_darwin";
