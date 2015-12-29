$NetBSD: patch-ref.c,v 1.2 2015/12/29 04:22:33 dholland Exp $

Fix symbol name conflict with posix getline().

--- ref.c.orig	2003-10-21 04:32:25.000000000 +0200
+++ ref.c
@@ -42,7 +42,7 @@ typedef enum
 
 #if USE_PROTOTYPES
 static void usage(char *argv0);
-static char *getline(FILE *fp);
+static char *_getline(FILE *fp);
 static void store(char *line, char **list);
 static LINECLS classify(char *line, LINECLS prev);
 static void lookup(TAG *tag);
@@ -171,7 +171,7 @@ ELVBOOL ioclose()
 /* This function reads a single line, and replaces the terminating newline with
  * a '\0' byte.  The string will be in a static buffer.  Returns NULL at EOF.
  */
-static char *getline(fp)
+static char *_getline(fp)
 	FILE	*fp;
 {
 	int	ch;
@@ -348,7 +348,7 @@ static void lookup(tag)
 	}
 
 	/* for each line... */
-	for (lnum = 1, lc = LC_COMPLETE; (line = getline(fp)) != NULL; lnum++)
+	for (lnum = 1, lc = LC_COMPLETE; (line = _getline(fp)) != NULL; lnum++)
 	{
 		/* is this the tag definition? */
 		if (taglnum > 0 ? taglnum == lnum : !strncmp(tagline, line, len))
@@ -377,7 +377,7 @@ static void lookup(tag)
 			{
 				if (strchr(line, '(') != NULL)
 				{
-					while ((line = getline(fp)) != NULL
+					while ((line = _getline(fp)) != NULL
 					    && *line
 					    && ((*line != '#' && *line != '{')
 						|| line[strlen(line) - 1] == '\\'))
@@ -387,7 +387,7 @@ static void lookup(tag)
 				}
 				else if ((lc = classify(line, lc)) == LC_PARTIAL)
 				{
-					while ((line = getline(fp)) != NULL
+					while ((line = _getline(fp)) != NULL
 					    && (lc = classify(line, lc)) == LC_PARTIAL)
 					{
 						puts(line);
