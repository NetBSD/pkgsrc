$NetBSD: patch-playtreeparser.c,v 1.1 2025/11/15 12:43:18 ryoon Exp $

--- playtreeparser.c.orig	2025-10-08 03:27:51.067895472 +0000
+++ playtreeparser.c
@@ -657,12 +657,12 @@ parse_textplain(play_tree_parser_t* p) {
     if (strlen(line) > 5)
       for(c = line; c[0]; c++ )
         if ( ((c[0] == '.') && //start with . and next have smil with optional ? or &
-           (tolower(c[1]) == 's') && (tolower(c[2])== 'm') &&
-           (tolower(c[3]) == 'i') && (tolower(c[4]) == 'l') &&
+           (tolower((unsigned char)(c[1])) == 's') && (tolower((unsigned char)(c[2]))== 'm') &&
+           (tolower((unsigned char)(c[3])) == 'i') && (tolower((unsigned char)(c[4])) == 'l') &&
            (!c[5] || c[5] == '?' || c[5] == '&')) || // or
           ((c[0] == '.') && // start with . and next have smi or ram with optional ? or &
-          ( ((tolower(c[1]) == 's') && (tolower(c[2])== 'm') && (tolower(c[3]) == 'i')) ||
-            ((tolower(c[1]) == 'r') && (tolower(c[2])== 'a') && (tolower(c[3]) == 'm')) )
+          ( ((tolower((unsigned char)(c[1])) == 's') && (tolower((unsigned char)(c[2]))== 'm') && (tolower((unsigned char)(c[3])) == 'i')) ||
+            ((tolower((unsigned char)(c[1])) == 'r') && (tolower((unsigned char)(c[2]))== 'a') && (tolower((unsigned char)(c[3])) == 'm')) )
            && (!c[4] || c[4] == '?' || c[4] == '&')) ){
           entry=embedded_playlist_parse(line);
           embedded = 1;
