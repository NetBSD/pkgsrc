$NetBSD: patch-cli_src_cli-cmd-parser.c,v 1.1 2024/08/06 18:54:01 riastradh Exp $

Avoid ctype(3) abuse.

--- cli/src/cli-cmd-parser.c.orig	2023-04-06 09:01:24.665967213 +0000
+++ cli/src/cli-cmd-parser.c
@@ -536,7 +536,7 @@ cli_validate_volname(const char *volname
     }
 
     for (i = 0; i < volname_len; i++) {
-        if (!isalnum(volname[i]) && (volname[i] != '_') &&
+        if (!isalnum((unsigned char)volname[i]) && (volname[i] != '_') &&
             (volname[i] != '-')) {
             cli_err(
                 "Volume name should not contain \"%c\""
@@ -4068,7 +4068,7 @@ cli_snap_clone_parse(dict_t *dict, const
     clonename = (char *)words[cmdi];
     for (i = 0; i < strlen(clonename); i++) {
         /* Following volume name convention */
-        if (!isalnum(clonename[i]) &&
+        if (!isalnum((unsigned char)clonename[i]) &&
             (clonename[i] != '_' && (clonename[i] != '-'))) {
             /* TODO : Is this message enough?? */
             cli_err(
@@ -4150,7 +4150,7 @@ cli_snap_create_parse(dict_t *dict, cons
     snapname = (char *)words[cmdi];
     for (i = 0; i < strlen(snapname); i++) {
         /* Following volume name convention */
-        if (!isalnum(snapname[i]) &&
+        if (!isalnum((unsigned char)snapname[i]) &&
             (snapname[i] != '_' && (snapname[i] != '-'))) {
             /* TODO : Is this message enough?? */
             cli_err(
@@ -5363,7 +5363,7 @@ cli_cmd_validate_volume(char *volname)
     }
 
     for (i = 0; i < volname_len; i++)
-        if (!isalnum(volname[i]) && (volname[i] != '_') &&
+        if (!isalnum((unsigned char)volname[i]) && (volname[i] != '_') &&
             (volname[i] != '-')) {
             cli_err(
                 "Volume name should not contain \"%c\""
