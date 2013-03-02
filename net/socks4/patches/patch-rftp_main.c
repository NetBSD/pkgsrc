$NetBSD: patch-rftp_main.c,v 1.1 2013/03/02 18:29:48 joerg Exp $

--- rftp/main.c.orig	1994-07-05 19:47:08.000000000 +0000
+++ rftp/main.c
@@ -58,6 +58,8 @@ static char sccsid[] = "@(#)main.c	5.18 
 #include <netdb.h>
 #include <pwd.h>
 
+void help(int argc, char *argv[]);
+
 uid_t	getuid();
 void	intr(), lostpeer();
 extern	char *home;
@@ -228,7 +230,6 @@ cmdscanner(top)
 	register struct cmd *c;
 	register int l;
 	struct cmd *getcmd();
-	extern int help();
 
 	if (!top)
 		(void) putchar('\n');
@@ -458,9 +459,7 @@ OUT:
  * Help command.
  * Call each command handler with argc == 0 and argv[0] == name.
  */
-help(argc, argv)
-	int argc;
-	char *argv[];
+void help(int argc, char *argv[])
 {
 	extern struct cmd cmdtab[];
 	register struct cmd *c;
