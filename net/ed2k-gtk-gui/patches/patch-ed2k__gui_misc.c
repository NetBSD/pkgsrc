$NetBSD: patch-ed2k__gui_misc.c,v 1.1 2014/09/10 12:22:44 joerg Exp $

--- ed2k_gui/misc.c.orig	2014-09-09 18:26:33.000000000 +0000
+++ ed2k_gui/misc.c
@@ -1655,7 +1655,7 @@ misc_remove_junk_from_servername (const 
 			gchar *nospace = pos+2;
 			while (*nospace == ' ')
 				nospace++;
-			g_memmove(pos+1, nospace, strlen(nospace) + 1);
+			memmove(pos+1, nospace, strlen(nospace) + 1);
 		}
 		pos++;
 	}
