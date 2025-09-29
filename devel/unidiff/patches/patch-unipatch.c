$NetBSD: patch-unipatch.c,v 1.1 2025/09/29 20:45:38 mrg Exp $

Fix compilation with GCC 14.

--- unipatch.c.orig	2022-07-11 18:28:40.000000000 -0700
+++ unipatch.c	2025-09-25 10:50:30.824061017 -0700
@@ -3,12 +3,15 @@
 for patch. Version 1.1. Author: davison@borland.com
 */
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+
 #define ERR(a) {fputs(a,stderr);exit(1);}
 #define NUM(x) {for(x=0;*cp<='9'&&*cp>='0';)x=x*10+*cp++-'0';ch= *cp++;}
 struct Ln {struct Ln *lk; char t; char s[1];} r,*h,*ln;
-char bf[2048],*cp,ch,*malloc();
+char bf[2048],*cp,ch;
 long os,ol,ns,nl,ne,lncnt;
-main()
+void main()
 {
  for(;;){
   for(;;){
