$NetBSD: patch-print.c,v 1.1 2013/07/18 12:05:09 joerg Exp $

--- print.c.orig	2013-07-17 14:26:15.000000000 +0000
+++ print.c
@@ -229,7 +229,7 @@ void real_print_node(FILE *strm, NODE *n
 	if (print_backslashes && (getarrorg(nd) != 1)) {
 	    char org[] = "@	";
 
-	    sprintf(&org[1],"%d",getarrorg(nd));
+	    sprintf(&org[1],"%ld",getarrorg(nd));
 	    ndprintf(strm,org);
 	}
     } else if (ndty == QUOTE) {
