$NetBSD: patch-media_libtheora_lib_info.c,v 1.1 2023/02/05 08:32:24 he Exp $

--- media/libtheora/lib/info.c.orig	2020-08-28 21:32:52.000000000 +0000
+++ media/libtheora/lib/info.c
@@ -29,7 +29,7 @@
 static int oc_tagcompare(const char *_s1,const char *_s2,int _n){
   int c;
   for(c=0;c<_n;c++){
-    if(toupper(_s1[c])!=toupper(_s2[c]))return !0;
+    if(toupper((unsigned char)_s1[c])!=toupper((unsigned char)_s2[c]))return !0;
   }
   return _s1[c]!='=';
 }
