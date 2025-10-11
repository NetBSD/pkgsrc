$NetBSD: patch-support_genmk_genmk.c,v 1.1 2025/10/11 21:14:32 mrg Exp $

Add missing types/prototypes for GCC 14.


--- support/genmk/genmk.c.orig	2000-12-04 08:05:21.000000000 -0800
+++ support/genmk/genmk.c	2025-10-11 14:11:18.509028225 -0700
@@ -73,12 +73,14 @@ void mk(char *project, char **files, int
 void pfiles(char **files, int n, char *suffix);
 void fatal(char *msg);
 void warn(char *msg);
+void pclasses(char **classes, int n, char *suffix);
 #else
 void help();
 void mk();
 void pfiles();
 void fatal();
 void warn();
+void pclasses();
 #endif
 
 typedef struct _Opt {
@@ -966,6 +968,7 @@ char *suffix;
 }
 
 #ifdef __STDC__
+void
 pclasses(char **classes, int n, char *suffix)
 #else
 pclasses(classes, n, suffix)
