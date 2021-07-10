$NetBSD: patch-lib_pager.c,v 1.1 2021/07/10 23:11:22 dholland Exp $

select's fd_set arguments are declared "restrict" so don't pass aliased
pointers. note that nothing following actually _uses_ the data...

--- lib/pager.c~	2018-06-04 07:57:02.793445882 +0000
+++ lib/pager.c
@@ -141,11 +141,13 @@ static void pager_preexec(void)
 	 * Work around bug in "less" by not starting it until we
 	 * have real input
 	 */
-	fd_set in;
+	fd_set in, ex;
 
 	FD_ZERO(&in);
 	FD_SET(STDIN_FILENO, &in);
-	select(1, &in, NULL, &in, NULL);
+	FD_ZERO(&ex);
+	FD_SET(STDIN_FILENO, &ex);
+	select(1, &in, NULL, &ex, NULL);
 
 	if (setenv("LESS", "FRSX", 0) != 0)
 		warn(_("failed to set the %s environment variable"), "LESS");
