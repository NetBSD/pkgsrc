$NetBSD: patch-web_showgraph.c,v 1.1 2019/11/24 20:16:55 spz Exp $

from https://sourceforge.net/p/xymon/code/8076/
Fix truncation on exec strings causing missing custom RRD titles (Thanks, Tom Schmidt)

--- web/showgraph.c.orig	2019-07-23 14:46:51.000000000 +0000
+++ web/showgraph.c
@@ -1081,10 +1084,10 @@ void generate_graph(char *gdeffn, char *
 		for (i=0; (i<rrddbcount); i++) pcmdlen += (strlen(rrddbs[i].rrdfn) + 3);
 
 		p = pcmd = (char *)malloc(pcmdlen+1);
-		p += snprintf(p, (pcmdlen - (p - pcmd)), param_str, gdef->title+5, displayname, service, glegend);
+		p += snprintf(p, pcmdlen+1, param_str, gdef->title+5, displayname, service, glegend);
 		for (i=0; (i<rrddbcount); i++) {
 			if ((firstidx == -1) || ((i >= firstidx) && (i <= lastidx))) {
-				p += snprintf(p, (pcmdlen - (p - pcmd)), " \"%s\"", rrddbs[i].rrdfn);
+				p += snprintf(p, (pcmdlen - (p - pcmd) + 1), " \"%s\"", rrddbs[i].rrdfn);
 			}
 		}
 		pfd = popen(pcmd, "r");
