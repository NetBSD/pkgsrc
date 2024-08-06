$NetBSD: patch-cli_src_cli-cmd-parser.c,v 1.2 2024/08/06 21:10:48 riastradh Exp $

Avoid ctype(3) abuse.
https://github.com/gluster/glusterfs/issues/4397

--- cli/src/cli-cmd-parser.c.orig	2024-08-06 15:42:52.470503130 +0000
+++ cli/src/cli-cmd-parser.c
@@ -535,7 +535,7 @@ cli_validate_volname(const char *volname
     }
 
     for (i = 0; i < volname_len; i++) {
-        if (!isalnum(volname[i]) && (volname[i] != '_') &&
+        if (!isalnum((unsigned char)volname[i]) && (volname[i] != '_') &&
             (volname[i] != '-')) {
             cli_err(
                 "Volume name should not contain \"%c\""
@@ -4273,7 +4273,7 @@ cli_snap_clone_parse(dict_t *dict, const
     clonename = (char *)words[cmdi];
     for (i = 0; i < strlen(clonename); i++) {
         /* Following volume name convention */
-        if (!isalnum(clonename[i]) &&
+        if (!isalnum((unsigned char)clonename[i]) &&
             (clonename[i] != '_' && (clonename[i] != '-'))) {
             /* TODO : Is this message enough?? */
             cli_err(
@@ -4356,7 +4356,7 @@ cli_snap_create_parse(dict_t *dict, cons
     snapname = (char *)words[cmdi];
     for (i = 0; i < strlen(snapname); i++) {
         /* Following volume name convention */
-        if (!isalnum(snapname[i]) &&
+        if (!isalnum((unsigned char)snapname[i]) &&
             (snapname[i] != '_' && (snapname[i] != '-'))) {
             /* TODO : Is this message enough?? */
             cli_err(
@@ -5563,7 +5563,7 @@ cli_cmd_validate_volume(char *volname)
     }
 
     for (i = 0; i < volname_len; i++)
-        if (!isalnum(volname[i]) && (volname[i] != '_') &&
+        if (!isalnum((unsigned char)volname[i]) && (volname[i] != '_') &&
             (volname[i] != '-')) {
             cli_err(
                 "Volume name should not contain \"%c\""
