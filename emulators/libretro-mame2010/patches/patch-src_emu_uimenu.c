$NetBSD: patch-src_emu_uimenu.c,v 1.2 2021/06/19 07:23:31 nia Exp $

Consistently build as C++11 source, but ignore narrow issues.
Don't depend on ordering of pointers relative to zero. Avoid UDL.

--- src/emu/uimenu.c.orig	2020-05-13 17:06:07.589487572 +0000
+++ src/emu/uimenu.c
@@ -3516,9 +3516,9 @@ static void menu_select_game_populate(ru
 	/* if nothing there, add a single multiline item and return */
 	if (matchcount == 0)
 	{
-		ui_menu_item_append(menu, "No "GAMESNOUN" found. Please check the rompath specified in the "CONFIGNAME".ini file.\n\n"
-								  "If this is your first time using "APPNAME", please see the config.txt file in "
-								  "the docs directory for information on configuring "APPNAME".", NULL, MENU_FLAG_MULTILINE | MENU_FLAG_REDTEXT, NULL);
+		ui_menu_item_append(menu, "No " GAMESNOUN " found. Please check the rompath specified in the " CONFIGNAME ".ini file.\n\n"
+								  "If this is your first time using " APPNAME ", please see the config.txt file in "
+								  "the docs directory for information on configuring " APPNAME ".", NULL, MENU_FLAG_MULTILINE | MENU_FLAG_REDTEXT, NULL);
 		return;
 	}
 
