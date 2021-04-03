$NetBSD: patch-code_q3__ui_ui__preferences.c,v 1.1 2021/04/03 15:34:04 nia Exp $

Request confirmation if a user enables auto-downloading. From Debian.

--- code/q3_ui/ui_preferences.c.orig	2011-11-08 20:27:29.000000000 +0000
+++ code/q3_ui/ui_preferences.c
@@ -131,6 +131,41 @@ static void Preferences_SetMenuItems( vo
         s_preferences.teamchatbeep.curvalue     = trap_Cvar_VariableValue( "cg_teamChatBeep" ) != 0;
 }
 
+
+static void AutoDownloadAction( qboolean result )
+{
+	if (result) {
+		trap_Cvar_SetValue( "cl_allowDownload", 1 );
+	} else {
+		trap_Cvar_SetValue( "cl_allowDownload", 0 );
+	}
+	s_preferences.allowdownload.curvalue = result;
+}
+
+static void UI_ConfirmAutoDownload_Draw ( void )
+{
+	UI_DrawProportionalString( SCREEN_WIDTH/2, 356 + PROP_HEIGHT * 0,
+		"WARNING: This is a security risk.",
+		UI_CENTER|UI_SMALLFONT, color_yellow );
+	UI_DrawProportionalString( SCREEN_WIDTH/2, 356 + PROP_HEIGHT * 1,
+		"More information: <http://deb.li/Q3DL>",
+		UI_CENTER|UI_SMALLFONT, color_yellow );
+}
+
+void UI_ConfirmAutoDownload( void (*action) (qboolean) )
+{
+	if (trap_Cvar_VariableValue( "cl_allowDownload" ) != 0) {
+		/* already set */
+		return;
+	}
+
+	UI_ConfirmMenu_Style(
+		"Auto-download?",
+		UI_CENTER|UI_SMALLFONT,
+		UI_ConfirmAutoDownload_Draw,
+		action);
+}
+
 static void Preferences_Event( void* ptr, int notification ) {
 	if( notification != QM_ACTIVATED ) {
 		return;
@@ -216,8 +251,11 @@ static void Preferences_Event( void* ptr
 		break;
 
 	case ID_ALLOWDOWNLOAD:
-		trap_Cvar_SetValue( "cl_allowDownload", s_preferences.allowdownload.curvalue );
 		trap_Cvar_SetValue( "sv_allowDownload", s_preferences.allowdownload.curvalue );
+		if ( s_preferences.allowdownload.curvalue )
+			UI_ConfirmAutoDownload( AutoDownloadAction );
+		else
+			trap_Cvar_SetValue( "cl_allowDownload", 0 );
 		break;
                
         case ID_DELAGHITSCAN:
