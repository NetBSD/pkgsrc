$NetBSD: patch-main_tdd.c,v 1.1 2024/10/21 05:12:47 jnemeth Exp $

--- main/tdd.c.orig	2018-05-07 17:30:59.571540797 +0000
+++ main/tdd.c
@@ -313,7 +313,7 @@ int tdd_generate(struct tdd_state *tdd, 
 		if ( (tdd->charnum++) % 72 == 0)
 			PUT_TDD(tdd->mode ? 27 /* FIGS */ : 31 /* LTRS */);
 
-		c = toupper(str[x]);
+		c = toupper((unsigned char)str[x]);
 #if	0
 		printf("%c",c); fflush(stdout);
 #endif
