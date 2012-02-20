$NetBSD: patch-src-linux.c,v 1.1 2012/02/20 15:45:19 reinoud Exp $

--- src/linux.c.orig	2011-02-12 15:52:50.000000000 +0000
+++ src/linux.c
@@ -62,6 +62,8 @@ int main(int argc, char *argv[])
         get_executable_name(exedir,511);
         p=get_filename(exedir);
         p[0]=0;
+	/* data was referred relative to the executable; fix: */
+	strcpy(exedir, "@BEMDATADIR@");
         loadconfig();
 //        printf("Main\n");
         initbbc(argc,argv);
