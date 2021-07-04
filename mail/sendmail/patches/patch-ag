$NetBSD: patch-ag,v 1.15 2021/07/04 07:57:13 jnemeth Exp $

--- include/sm/conf.h.orig	2020-06-04 06:27:49.000000000 +0000
+++ include/sm/conf.h
@@ -381,7 +381,7 @@ typedef int		pid_t;
 #   ifndef __svr4__
 #    define __svr4__		/* use all System V Release 4 defines below */
 #   endif
-#   if SOLARIS >= 21100
+#   if SOLARIS >= 21100 && defined(SOLARIS_HAS_PATHS_H)
 #    include <paths.h>
 #   endif
 #   ifndef _PATH_VARRUN
@@ -827,7 +827,11 @@ extern unsigned int sleepX __P((unsigned
 #  ifndef LA_TYPE
 #   define LA_TYPE	LA_SUBR
 #  endif
-#  define SFS_TYPE	SFS_MOUNT	/* use <sys/mount.h> statfs() impl */
+#  if defined(__NetBSD__) && (__NetBSD_Version__ > 299000900)
+#   define SFS_TYPE    SFS_STATVFS     /* use <sys/statvfs.h> statfs() impl */
+#  else
+#   define SFS_TYPE    SFS_MOUNT       /* use <sys/mount.h> statfs() impl */
+#  endif
 #  define SPT_TYPE	SPT_PSSTRINGS	/* use PS_STRINGS pointer */
 # endif /* defined(BSD4_4) && !defined(__bsdi__) && !defined(__GNU__) && !defined(DARWIN)*/
 
