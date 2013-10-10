$NetBSD: patch-src_mkobexcard.c,v 1.1 2013/10/10 00:02:17 joerg Exp $

--- src/mkobexcard.c.orig	2013-10-09 23:07:15.000000000 +0000
+++ src/mkobexcard.c
@@ -142,7 +142,7 @@ int main(int argc, char** argv)
 	  addStr(company);
 	  addChar('\n');
 	  if (name[0] == '\0')
-	      snprintf(name, MAXNAME+1, company);
+	      snprintf(name, MAXNAME+1, "%s", company);
       }
       if (title) {
 	  addStr("TITLE:");
