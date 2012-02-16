$NetBSD: patch-teleinfo.c,v 1.1 2012/02/16 18:00:20 hans Exp $

--- teleinfo.c.orig	2012-01-26 22:15:20.421519776 +0100
+++ teleinfo.c	2012-01-26 22:17:29.154924079 +0100
@@ -24,6 +24,10 @@ char rcsid_teleinfo_c[] = "$Id: teleinfo
  * Inspire du programme "minitel" de Sylvain Meunier...
  */
 
+#ifdef __sun
+#include <sys/stropts.h>
+#endif
+
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
@@ -74,7 +78,7 @@ int *pl, *pc;
      */
     strcpy (master, "/dev/ptmx");
     if ((fd_master = open ("/dev/ptmx", O_RDWR)) < 0)
-	teleinfo_fatal ("/dev/ptmx", sys_errlist[errno]);
+	teleinfo_fatal ("/dev/ptmx", strerror(errno));
     sighold (SIGCLD);
     if (grantpt (fd_master) == -1)
 	teleinfo_fatal ("could not grant slave pty");
@@ -136,7 +140,7 @@ char *nom;
 	teleinfo_fatal ("erreur ouverture maitre");
 
     if ((fd_teleinfo = open (pty_s, O_RDWR)) < 0)
-	teleinfo_fatal (pty_s, sys_errlist[errno]);
+	teleinfo_fatal (pty_s, strerror(errno));
 
     /* Configuration de la ligne (mode RAW) */
 #ifdef SVR4    
