$NetBSD: patch-cmdline.c,v 1.1.1.1 2009/01/23 13:35:30 sborrill Exp $

Remove code which attempts to read svn revision numbers from source files for use in comments
Fix spelling mistake

--- cmdline.c.orig	2009-01-23 13:00:08.000000000 +0000
+++ cmdline.c	2009-01-23 13:01:02.000000000 +0000
@@ -38,14 +38,14 @@
 static char *getCredentialsFromFile( const char* filename, char **user, char **pass, char **rem_user, char **rem_pass);
 
 void cmdline_parser_print_version (void) {
-	printf ("%s %s (rev %d) Copyright 2001-2008 Proxytunnel Project\n", PACKAGE, VERSION, REV);
+	printf ("%s %s Copyright 2001-2008 Proxytunnel Project\n", PACKAGE, VERSION);
 }
 
 void cmdline_parser_print_help (void) {
 	cmdline_parser_print_version ();
 	printf(
 "Usage: %s [OPTIONS]...\n"
-"Build generic tunnels trough HTTPS proxy's, supports HTTP authorization\n"
+"Build generic tunnels trough HTTPS proxies, supports HTTP authorization\n"
 "\n"
 "Standard options:\n"
 // FIXME: "   -c, --config=FILE       Read config options from file\n"
