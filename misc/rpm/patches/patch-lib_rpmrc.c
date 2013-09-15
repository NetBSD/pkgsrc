$NetBSD: patch-lib_rpmrc.c,v 1.1 2013/09/15 12:32:22 joerg Exp $

--- lib/rpmrc.c.orig	2013-09-14 21:00:41.000000000 +0000
+++ lib/rpmrc.c
@@ -991,7 +991,7 @@ static void defaultMachine(const char **
 	else if(rstreq(un.sysname, "Darwin")) { 
 #ifdef __ppc__
 	    strcpy(un.machine, "ppc");
-#else ifdef __i386__
+#elif defined(__i386__)
 	    strcpy(un.machine, "i386");
 #endif 
 	}
