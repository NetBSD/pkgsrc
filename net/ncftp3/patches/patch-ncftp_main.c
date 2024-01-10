$NetBSD: patch-ncftp_main.c,v 1.1 2024/01/10 18:01:55 adam Exp $

Make ncftp build reproducible.
https://bugs.debian.org/829249

--- ncftp/main.c.orig	2016-11-16 00:29:47.000000000 +0000
+++ ncftp/main.c
@@ -65,7 +65,7 @@ __attribute__ ((noreturn))
 Usage(void)
 {
 	FILE *fp;
-#ifdef UNAME
+#if 0
 	char s[80];
 #endif
 
@@ -79,7 +79,7 @@ Usage(void)
   -F     Dump a sample $HOME/.ncftp/firewall prefs file to stdout and exit.\n");
 
 	(void) fprintf(fp, "\nProgram version:  %s\nLibrary version:  %s\n", gVersion + 5, gLibNcFTPVersion + 5);
-#ifdef UNAME
+#if 0
 	AbbrevStr(s, UNAME, 60, 1);
 	(void) fprintf(fp, "Build system:     %s\n", s);
 #endif
