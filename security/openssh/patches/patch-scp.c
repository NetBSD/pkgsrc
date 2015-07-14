$NetBSD: patch-scp.c,v 1.2.14.1 2015/07/14 22:03:39 tron Exp $

Interix support

--- scp.c.orig	2015-07-01 02:35:31.000000000 +0000
+++ scp.c
@@ -478,7 +478,11 @@ main(int argc, char **argv)
 	argc -= optind;
 	argv += optind;
 
+#ifdef HAVE_INTERIX
+	if ((pwd = getpwuid_ex(userid = getuid(), PW_FULLNAME)) == NULL)
+#else
 	if ((pwd = getpwuid(userid = getuid())) == NULL)
+#endif
 		fatal("unknown user %u", (u_int) userid);
 
 	if (!isatty(STDOUT_FILENO))
@@ -886,8 +890,10 @@ rsource(char *name, struct stat *statp)
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
@@ -1297,7 +1303,9 @@ okname(char *cp0)
 			case '\'':
 			case '"':
 			case '`':
+#ifndef HAVE_INTERIX
 			case ' ':
+#endif
 			case '#':
 				goto bad;
 			default:
