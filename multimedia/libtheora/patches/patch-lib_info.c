$NetBSD: patch-lib_info.c,v 1.1 2025/05/01 07:57:24 nia Exp $

Avoid undefined behaviour with ctype functions.
https://gitlab.xiph.org/xiph/theora/-/issues/2342

--- lib/info.c.orig	2025-03-29 06:06:12.000000000 +0000
+++ lib/info.c
@@ -29,7 +29,9 @@
 static int oc_tagcompare(const char *_s1,const char *_s2,int _n){
   int c;
   for(c=0;c<_n;c++){
-    if(toupper(_s1[c])!=toupper(_s2[c]))return !0;
+    if(toupper((unsigned char)_s1[c])!=toupper((unsigned char)_s2[c])){
+      return !0;
+    }
   }
   return _s1[c]!='=';
 }
