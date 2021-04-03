$NetBSD: patch-code_q3__ui_ui__firstconnect.c,v 1.1 2021/04/03 15:34:04 nia Exp $

Request confirmation if a user enables auto-downloading, since it is a
security risk. From Debian.

--- code/q3_ui/ui_firstconnect.c.orig	2011-11-08 20:27:29.000000000 +0000
+++ code/q3_ui/ui_firstconnect.c
@@ -194,7 +194,17 @@ FirstConnect_StatusBar_Download
 =================
 */
 static void FirstConnect_StatusBar_Download( void* ptr ) {
-		UI_DrawString( 320, 440, "Auto download missing maps and mods", UI_CENTER|UI_SMALLFONT, colorWhite );
+		UI_DrawString( 320, 440, "Security risk, see <http://deb.li/Q3DL>", UI_CENTER|UI_SMALLFONT, colorWhite );
+}
+
+static void AutoDownloadAction( qboolean result )
+{
+	if (result) {
+		trap_Cvar_SetValue( "cl_allowDownload", 1 );
+	} else {
+		trap_Cvar_SetValue( "cl_allowDownload", 0 );
+	}
+	s_firstconnect.allowdownload.curvalue = result;
 }
 
 /*
@@ -251,8 +261,11 @@ static void FirstConnect_Event( void* pt
                         break;
 
                 case ID_ALLOWDOWNLOAD:
-                        trap_Cvar_SetValue( "cl_allowDownload", s_firstconnect.allowdownload.curvalue );
                         trap_Cvar_SetValue( "sv_allowDownload", s_firstconnect.allowdownload.curvalue );
+                        if ( s_firstconnect.allowdownload.curvalue )
+				UI_ConfirmAutoDownload( AutoDownloadAction );
+			else
+				trap_Cvar_SetValue( "cl_allowDownload", 0 );
                         break;
 
                 case ID_DELAGHITSCAN:
