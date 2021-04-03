$NetBSD: patch-code_q3__ui_ui__local.h,v 1.1 2021/04/03 15:34:04 nia Exp $

Request confirmation if a user enables auto-downloading, since it is a
security risk. From Debian.

--- code/q3_ui/ui_local.h.orig	2011-11-08 20:27:29.000000000 +0000
+++ code/q3_ui/ui_local.h
@@ -458,6 +458,7 @@ extern void PlayerSettings_Cache( void )
 // ui_preferences.c
 //
 extern void UI_PreferencesMenu( void );
+extern void UI_ConfirmAutoDownload( void (*action) (qboolean) );
 extern void Preferences_Cache( void );
 
 //
