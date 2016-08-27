$NetBSD: patch-src_rrd__xport.c,v 1.1 2016/08/27 07:40:23 dholland Exp $

Use <ctype.h> correctly.

--- src/rrd_xport.c~	2016-04-19 15:52:26.000000000 +0000
+++ src/rrd_xport.c
@@ -547,7 +547,7 @@ int rrd_xport_format_sv(char sep, string
   if (addToBuffer(buffer,"\"time\"",6)) { return 1; }
   for(unsigned long i=0;i<col_cnt;i++) {
     /* strip leading spaces */
-    char *t=legend_v[i]; while (isspace(*t)) { t++;}
+    char *t=legend_v[i]; while (isspace((unsigned char)*t)) { t++;}
     /* and print it */
     snprintf(buf,255,"%c\"%s\"",sep,t);
     if (addToBuffer(buffer,buf,0)) { return 1;}
@@ -690,7 +690,7 @@ int rrd_xport_format_xmljson(int flags,s
   for (unsigned long j = 0; j < col_cnt; j++) {
     char *entry = legend_v[j];
     /* I do not know why the legend is "spaced", but let us skip it */
-    while(isspace(*entry)){entry++;}
+    while(isspace((unsigned char)*entry)){entry++;}
     /* now output it */
     if (json){
       snprintf(buf,sizeof(buf),"      \"%s\"", entry);
@@ -977,7 +977,7 @@ int rrd_xport_format_addprints(int flags
     case GF_LINE:
       entry = im->gdes[i].legend;
       /* I do not know why the legend is "spaced", but let us skip it */
-      while(isspace(*entry)){entry++;}
+      while(isspace((unsigned char)*entry)){entry++;}
       if (json) {
         snprintf(buf,sizeof(buf),",\n        { \"line\": \"%s\" }",entry);
       } else {
