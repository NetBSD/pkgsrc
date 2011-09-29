$NetBSD: patch-__nilsimsa.c,v 1.1 2011/09/29 21:10:33 wiz Exp $

Fix build on systems that define popcount().

--- _nilsimsa.c.orig	2002-06-13 04:15:03.000000000 +0000
+++ _nilsimsa.c
@@ -48,7 +48,7 @@
 */
 
 unsigned int acc[256],threshold;
-unsigned char tran[256],popcount[256];
+unsigned char tran[256],pop_count[256];
 struct nsrecord *selkarbi,terkarbi,*rules,gunma;
 int nilselkarbi,nrules;
 char *comparestr,*rulefile,*checkrulefile;
@@ -90,10 +90,10 @@ void dumptran()
 
 void fillpopcount()
 {int i,j;
- memset(popcount,0,256);
+ memset(pop_count,0,256);
  for (i=0;i<256;i++)
      for (j=0;j<8;j++)
-         popcount[i]+=1&(i>>j);
+         pop_count[i]+=1&(i>>j);
  }
 
 int defromulate(FILE *file)
@@ -384,7 +384,7 @@ void makecode(struct nsrecord *a)
 int nilsimsa(struct nsrecord *a,struct nsrecord *b)
 {int i,bits;
  for (i=bits=0;i<32;i++)
-     bits+=popcount[255&(a->code[i]^b->code[i])];
+     bits+=pop_count[255&(a->code[i]^b->code[i])];
  return 128-bits;
  }
 
