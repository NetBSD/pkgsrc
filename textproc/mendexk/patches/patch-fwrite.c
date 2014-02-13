$NetBSD: patch-fwrite.c,v 1.1 2014/02/13 00:58:22 minskim Exp $

Fix https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=534641.
Patch from TeX Live svn r31621.

--- fwrite.c.orig	2012-10-16 08:06:04.000000000 +0000
+++ fwrite.c
@@ -15,7 +15,7 @@ static int range_check(struct index ind,
 static void linecheck(char *lbuff, char *tmpbuff);
 static void crcheck(char *lbuff, FILE *fp);
 
-#define TAIL(x) (x+strlen(x))
+#define TAIL(x) ((x)+strlen(x))
 
 /* if we don't have vsnprintf() */
 /* #define vsnprintf(buff,len,format,argptr) vsprintf(buff,format,argptr) */
@@ -385,7 +385,7 @@ static int range_check(struct index ind,
 					}
 					if (strlen(ind.p[j].enc)>0) {
 						sprintf(tmpbuff,"%s%s%s",encap_prefix,ind.p[j].enc,encap_infix);
-						sprintf(tmpbuff,"%s%s%s",ind.p[j].page,encap_suffix,delim_n);
+						sprintf(TAIL(tmpbuff),"%s%s%s",ind.p[j].page,encap_suffix,delim_n);
 						linecheck(lbuff,tmpbuff);
 					}
 				}
