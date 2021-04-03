$NetBSD: patch-code_game_g__cmds.c,v 1.1 2021/04/03 15:34:04 nia Exp $

A fix for Debian Bug #681812. Doing "callvote kick PLAYERNAME" for a
playername that did not exist results in undefined behavior.

Depending on architecture this results in a crash or something else.

--- code/game/g_cmds.c.orig	2011-11-08 20:27:32.000000000 +0000
+++ code/game/g_cmds.c
@@ -1812,7 +1812,7 @@ void Cmd_CallVote_f( gentity_t *ent ) {
 		Com_sprintf( level.voteDisplayString, sizeof( level.voteDisplayString ), "Shuffle teams?" );
         } else if ( !Q_stricmp( arg1, "kick" ) ) {
                 i = 0;
-                while(Q_stricmp(arg2,(g_entities+i)->client->pers.netname)) {
+                while((g_entities+i) == NULL || (g_entities+i)->client == NULL || Q_stricmp(arg2,(g_entities+i)->client->pers.netname)) {
                     //Not client i, try next
                     i++;
                     if(i>=MAX_CLIENTS){ //Only numbers <128 is clients
