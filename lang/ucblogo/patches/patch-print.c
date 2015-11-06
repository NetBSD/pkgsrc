$NetBSD: patch-print.c,v 1.2 2015/11/06 20:33:21 joerg Exp $

--- print.c.orig	2008-03-01 01:04:41.000000000 +0000
+++ print.c
@@ -254,7 +254,7 @@ void real_print_node(FILE *strm, NODE *n
     } else if ((unsigned int)nd < 200) {    /* for debugging */
 	char num[] = "{small}    ";
 
-	sprintf(&num[7],"%d",nd);
+	snprintf(&num[7], sizeof(num) - 7,"%u",(unsigned int)nd);
 	ndprintf(strm,num);
     } else if ((ndty = nodetype(nd)) & NT_PRIM) {
 	ndprintf(strm, "PRIM");
@@ -281,7 +281,7 @@ void real_print_node(FILE *strm, NODE *n
 	if (print_backslashes && (getarrorg(nd) != 1)) {
 	    char org[] = "@	";
 
-	    sprintf(&org[1],"%d",getarrorg(nd));
+	    sprintf(&org[1],"%ld",getarrorg(nd));
 	    ndprintf(strm,org);
 	}
     } else if (ndty == QUOTE) {
