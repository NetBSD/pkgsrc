$NetBSD: patch-kiten_xjdxgen.c,v 1.1 2012/06/25 11:31:20 joerg Exp $

--- kiten/xjdxgen.c.orig	2012-06-18 20:27:33.000000000 +0000
+++ kiten/xjdxgen.c
@@ -86,7 +86,7 @@ extern char *getenv(const char *name);
 /*====function to Load Dictionary and load/create index table=======*/
 int  main(argc,argv)
 int argc;
-unsigned char **argv;
+char **argv;
 {
   FILE *fp,*fopen();
   uint32_t possav,schi,diclen,indlen;
