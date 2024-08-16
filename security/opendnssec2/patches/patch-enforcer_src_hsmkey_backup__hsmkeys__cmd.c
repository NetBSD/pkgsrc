$NetBSD: patch-enforcer_src_hsmkey_backup__hsmkeys__cmd.c,v 1.1 2024/08/16 15:29:36 he Exp $

Provide more diagnostic information to the client.

--- enforcer/src/hsmkey/backup_hsmkeys_cmd.c.orig	2024-03-27 16:53:50.916681905 +0000
+++ enforcer/src/hsmkey/backup_hsmkeys_cmd.c
@@ -92,6 +92,7 @@ prepare(int sockfd, db_connection_t *dbc
     int keys_marked = hsmkeys_from_to_state(dbconn, clause_list,
         HSM_KEY_BACKUP_BACKUP_REQUIRED, HSM_KEY_BACKUP_BACKUP_REQUESTED);
     if (keys_marked < 0) {
+	client_printf(sockfd, "info: no keys flagged for backup!");
         return 1;
     }
     client_printf(sockfd,"info: keys flagged for backup: %d\n", keys_marked);
@@ -104,6 +105,7 @@ commit(int sockfd, db_connection_t *dbco
     int keys_marked = hsmkeys_from_to_state(dbconn, clause_list,
         HSM_KEY_BACKUP_BACKUP_REQUESTED, HSM_KEY_BACKUP_BACKUP_DONE);
     if (keys_marked < 0) {
+	client_printf(sockfd, "info: no keys with backup -> commit state change");
         return 1;
     }
     client_printf(sockfd,"info: keys marked backup done: %d\n", keys_marked);
