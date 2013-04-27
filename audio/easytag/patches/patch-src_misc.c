$NetBSD: patch-src_misc.c,v 1.1 2013/04/27 23:05:27 joerg Exp $

--- src/misc.c.orig	2013-02-05 22:42:37.000000000 +0000
+++ src/misc.c
@@ -875,9 +875,7 @@ Run_Audio_Player_Using_File_List (GList 
 
     if ( !(program_path = Check_If_Executable_Exists(AUDIO_FILE_PLAYER)) )
     {
-        gchar *msg = g_strdup_printf(_("The program '%s' cannot be found"),AUDIO_FILE_PLAYER);
-        Log_Print(LOG_ERROR,msg);
-        g_free(msg);
+        Log_Print(LOG_ERROR, _("The program '%s' cannot be found"),AUDIO_FILE_PLAYER);
         return;
     }
     g_free(program_path);
