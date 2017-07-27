$NetBSD: patch-src_rrd__xport.c,v 1.2 2017/07/27 18:31:20 adam Exp $

Use <ctype.h> correctly.

--- src/rrd_xport.c.orig	2017-05-16 12:26:46.000000000 +0000
+++ src/rrd_xport.c
@@ -537,7 +537,7 @@ static int rrd_xport_format_sv(char sep,
   if (addToBuffer(buffer,"\"time\"",6)) { return 1; }
   for(unsigned long i=0;i<col_cnt;i++) {
     /* strip leading spaces */
-    char *t=legend_v[i]; while (isspace(*t)) { t++;}
+    char *t=legend_v[i]; while (isspace((unsigned char)*t)) { t++;}
     /* and print it */
     snprintf(buf,255,"%c\"%s\"",sep,t);
     if (addToBuffer(buffer,buf,0)) { return 1;}
@@ -680,7 +680,7 @@ static int rrd_xport_format_xmljson(int 
   for (unsigned long j = 0; j < col_cnt; j++) {
     char *entry = legend_v[j];
     /* I do not know why the legend is "spaced", but let us skip it */
-    while(isspace(*entry)){entry++;}
+    while(isspace((unsigned char)*entry)){entry++;}
     /* now output it */
     if (json){
       snprintf(buf,sizeof(buf),"      \"%s\"", entry);
@@ -970,7 +970,7 @@ static int rrd_xport_format_addprints(in
     case GF_LINE:
       entry = im->gdes[i].legend;
       /* I do not know why the legend is "spaced", but let us skip it */
-      while(isspace(*entry)){entry++;}
+      while(isspace((unsigned char)*entry)){entry++;}
       if (json) {
         snprintf(buf,sizeof(buf),",\n        { \"line\": \"%s\" }",entry);
       } else {
