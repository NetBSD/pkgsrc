$NetBSD: patch-scp.c,v 1.2 2013/12/01 06:11:41 taca Exp $

Interix support

--- scp.c.orig	2013-07-18 06:11:25.000000000 +0000
+++ scp.c
@@ -477,7 +477,11 @@ main(int argc, char **argv)
 	argc -= optind;
 	argv += optind;
 
+#ifdef HAVE_INTERIX
+	if ((pwd = getpwuid_ex(userid = getuid(), PW_FULLNAME)) == NULL)
+#else
 	if ((pwd = getpwuid(userid = getuid())) == NULL)
+#endif
 		fatal("unknown user %u", (u_int) userid);
 
 	if (!isatty(STDOUT_FILENO))
@@ -881,8 +885,10 @@ rsource(char *name, struct stat *statp)
 		return;
 	}
 	while ((dp = readdir(dirp)) != NULL) {
+#ifndef HAVE_INTERIX
 		if (dp->d_ino == 0)
 			continue;
+#endif
 		if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, ".."))
 			continue;
 		if (strlen(name) + 1 + strlen(dp->d_name) >= sizeof(path) - 1) {
@@ -1292,7 +1298,9 @@ okname(char *cp0)
 			case '\'':
 			case '"':
 			case '`':
+#ifndef HAVE_INTERIX
 			case ' ':
+#endif
 			case '#':
 				goto bad;
 			default:
