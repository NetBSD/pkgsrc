$NetBSD: patch-exjdxgen.c,v 1.1 2013/01/17 16:00:02 joerg Exp $

--- exjdxgen.c.orig	2013-01-16 14:03:20.000000000 +0000
+++ exjdxgen.c
@@ -66,9 +66,7 @@ int stringcomp(unsigned char *s1, unsign
 }
 
 /*====function to Load Dictionary and load/create index table=======*/
-main(argc,argv)
-int argc;
-unsigned char **argv;
+main(int argc, char **argv)
 {
   FILE *fp,*fopen();
   unsigned long schi,diclen,indlen;
