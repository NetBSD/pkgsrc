$NetBSD: patch-tools_parser_lmp.c,v 1.1 2014/12/30 08:39:13 plunky Exp $

upstream irrelevancy

--- tools/parser/lmp.c.orig	2014-12-12 13:38:33.000000000 +0000
+++ tools/parser/lmp.c
@@ -685,7 +685,7 @@ static inline void version_dump(int leve
 	p_indent(level, frm);
 	tmp = lmp_vertostr(ver);
 	printf("VersNr %d (%s)\n", ver, tmp);
-	bt_free(tmp);
+	free(tmp);
 
 	p_indent(level, frm);
 	printf("CompId %d (%s)\n", compid, bt_compidtostr(compid));
