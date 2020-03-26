$NetBSD: patch-src_argp-local.h,v 1.3 2020/03/26 02:30:49 joerg Exp $

--- src/argp-local.h.orig	2003-11-25 23:51:41.000000000 +0000
+++ src/argp-local.h
@@ -10,6 +10,7 @@
 //
 
 #include <getopt.h>
+#include <stdlib.h>
 #include <string.h>
 #include <iostream>
 
@@ -65,7 +66,7 @@ const argp_option _argp_default_options[
 
 string _argp_progname(const char *arg)
 {
-char *p=strrchr(arg,'/');
+const char *p=strrchr(arg,'/');
 return p==NULL ? arg : p+1;
 }
 
@@ -196,7 +197,11 @@ for(p=_argp->options;p!=_argp_default_op
    if(!p->name && !p->key)
      p=_argp_default_options;
    memset(q,0,sizeof(option));
+#ifndef __sun
    q->name=p->name;
+#else
+   q->name=(char*)p->name;
+#endif
    q->has_arg=p->arg==NULL ? no_argument : required_argument;
    if(p->key>' ' && p->key<='z')
      {
