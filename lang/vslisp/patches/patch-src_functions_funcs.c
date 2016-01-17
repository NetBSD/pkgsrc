$NetBSD: patch-src_functions_funcs.c,v 1.1 2016/01/17 15:14:47 joerg Exp $

--- src/functions/funcs.c.orig	2016-01-16 13:50:27.000000000 +0000
+++ src/functions/funcs.c
@@ -56,7 +56,7 @@
     if(ss[i]==' ') 
       s[j++]='+';
     else
-      if((toupper(ss[i])>= 'A') && (toupper(ss[i]<='Z')))
+      if((toupper((unsigned char)ss[i])>= 'A') && (toupper((unsigned char)ss[i]<='Z')))
 	s[j++]=ss[i];
       else
 	if(ss[i]>='0' && ss[i]<='9') s[j++]=ss[i];
