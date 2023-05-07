Author: Reiner Herrmann <reiner@reiner-h.de>
Date: 2016-07-01 16:00:02 UTC
Bug-Debian: https://bugs.debian.org/829249

	make ncftp build reproducible.

diff --git a/ncftp/main.c b/ncftp/main.c
index a7fccac..b27a94e 100644
--- ncftp/main.c.orig
+++ ncftp/main.c
@@ -62,7 +62,7 @@ static void
 Usage(void)
 {
 	FILE *fp;
-#ifdef UNAME
+#if 0
 	char s[80];
 #endif
 
@@ -76,7 +76,7 @@ Usage(void)
   -F     Dump a sample $HOME/.ncftp/firewall prefs file to stdout and exit.\n");
 
 	(void) fprintf(fp, "\nProgram version:  %s\nLibrary version:  %s\n", gVersion + 5, gLibNcFTPVersion + 5);
-#ifdef UNAME
+#if 0
 	AbbrevStr(s, UNAME, 60, 1);
 	(void) fprintf(fp, "Build system:     %s\n", s);
 #endif

