$NetBSD: patch-trs_xinterface.c,v 1.1 2013/01/12 19:07:56 is Exp $

--- trs_xinterface.c.orig	2013-01-12 18:33:16.000000000 +0000
+++ trs_xinterface.c
@@ -360,7 +360,7 @@ int trs_parse_command_line(int argc, cha
     if (XrmGetResource(x_db, option, "Xtrs.Charset", &type, &value)) {
       charset_name = (char*) value.addr;
     }
-    if (isdigit(*charset_name)) {
+    if (isdigit((int)(unsigned char)*charset_name)) {
       trs_charset = atoi(charset_name);
       cur_char_width = 8 * scale_x;
     } else {
@@ -396,7 +396,7 @@ int trs_parse_command_line(int argc, cha
     if (XrmGetResource(x_db, option, "Xtrs.Charset", &type, &value)) {
       charset_name = (char*) value.addr;
     }
-    if (isdigit(*charset_name)) {
+    if (isdigit((int)(unsigned char)*charset_name)) {
       trs_charset = atoi(charset_name);
     } else {
       if (charset_name[0] == 'k'/*katakana*/) {
