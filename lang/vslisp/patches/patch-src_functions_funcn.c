$NetBSD: patch-src_functions_funcn.c,v 1.1 2016/01/17 15:14:47 joerg Exp $

--- src/functions/funcn.c.orig	2016-01-16 13:50:45.000000000 +0000
+++ src/functions/funcn.c
@@ -729,7 +729,7 @@ LIST L_Defefun(IL_PARS)
 
   while((ss[ii]=fgetc(FiI))!=' ' && ss[ii]!='(' &&
        ss[ii]!=')' && ss[ii]!='\n' && (!feof(FiI))) {
-   if(!isdigit(ss[ii])) {
+   if(!isdigit((unsigned char)ss[ii])) {
     if(ss[ii]!='\n' && ss[ii]!='+' && ss[ii]!='-' && ss[ii]!='.') id=0;} 
     else dg++;   
    ii++;
