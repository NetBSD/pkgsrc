$NetBSD: patch-ed2k__gui_misc__strings.c,v 1.1 2014/09/10 12:22:44 joerg Exp $

--- ed2k_gui/misc_strings.c.orig	2014-09-09 18:26:23.000000000 +0000
+++ ed2k_gui/misc_strings.c
@@ -50,7 +50,7 @@ misc_strings_unescape_url (gchar *s)
 		if (sscanf(found+1, "%2x", &hexval) == 1)
 		{
 			*found = (gchar)hexval;
-			g_memmove(found+1, found+3, strlen(found+3)+1);
+			memmove(found+1, found+3, strlen(found+3)+1);
 		}
 
 		pos++;
