$NetBSD: patch-xjdxgen.c,v 1.1 2013/01/17 16:00:02 joerg Exp $

--- xjdxgen.c.orig	2013-01-16 14:02:59.000000000 +0000
+++ xjdxgen.c
@@ -74,9 +74,7 @@ int stringcomp(unsigned char *s1, unsign
 }
 
 /*====function to Load Dictionary and load/create index table=======*/
-main(argc,argv)
-int argc;
-unsigned char **argv;
+main(int argc,char **argv)
 {
   FILE *fp,*fopen();
   unsigned long possav,schi,diclen,indlen;
