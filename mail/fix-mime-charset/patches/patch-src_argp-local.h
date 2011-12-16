$NetBSD: patch-src_argp-local.h,v 1.2 2011/12/16 16:55:25 hans Exp $

--- src/argp-local.h.orig	2011-11-24 00:53:41.000000000 +0000
+++ src/argp-local.h
@@ -10,6 +10,7 @@
 //
 
 #include <getopt.h>
+#include <stdlib.h>
 #include <string.h>
 #include <iostream>
 
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
