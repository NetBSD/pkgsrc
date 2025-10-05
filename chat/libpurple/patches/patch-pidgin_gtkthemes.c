$NetBSD: patch-pidgin_gtkthemes.c,v 1.1 2025/10/05 16:01:16 wiz Exp $

Fix -Wchar-subscripts in ctype(3) functions

--- pidgin/gtkthemes.c~	2024-09-17 10:52:23.000000000 +0200
+++ pidgin/gtkthemes.c	2025-10-05 15:02:26.450840225 +0200
@@ -287,7 +287,7 @@
 		}
 
 		i = buf;
-		while (isspace(*i))
+		while (isspace((unsigned char)*i))
 			i++;
 
 		if (*i == '[' && strchr(i, ']') && load) {
@@ -325,7 +325,7 @@
 				char l[64];
 				size_t li = 0;
 				char *next;
-				while (*i && !isspace(*i) && li < sizeof(l) - 1) {
+				while (*i && !isspace((unsigned char)*i) && li < sizeof(l) - 1) {
 					if (*i == '\\' && *(i+1) != '\0')
 						i++;
 					/* coverity[tainted_data] */
@@ -343,7 +343,7 @@
 					GtkIMHtmlSmiley *smiley = gtk_imhtml_smiley_create(sfile, l, hidden, 0);
 					list->smileys = g_slist_prepend(list->smileys, smiley);
 				}
-				while (isspace(*i))
+				while (isspace((unsigned char)*i))
 					i++;
 
 			}
