$NetBSD: patch-authenticate.c,v 1.1.2.2 2014/04/19 05:19:38 spz Exp $

Close the remote DoS vulnerability reported in CVE-2014-2855.

Patch taken from Samba GIT repository:

https://git.samba.org/?p=rsync.git;a=commitdiff;h=0dedfbce2c1b851684ba658861fe9d620636c56a

--- authenticate.c.orig	2013-06-09 20:11:53.000000000 +0100
+++ authenticate.c	2014-04-19 00:26:00.000000000 +0100
@@ -102,15 +102,16 @@
 	char pass2[MAX_DIGEST_LEN*2];
 	const char *fname = lp_secrets_file(module);
 	STRUCT_STAT st;
-	int fd, ok = 1;
+	int ok = 1;
 	int user_len = strlen(user);
 	int group_len = group ? strlen(group) : 0;
 	char *err;
+	FILE *fh;
 
-	if (!fname || !*fname || (fd = open(fname, O_RDONLY)) < 0)
+	if (!fname || !*fname || (fh = fopen(fname, "r")) == NULL)
 		return "no secrets file";
 
-	if (do_fstat(fd, &st) == -1) {
+	if (do_fstat(fileno(fh), &st) == -1) {
 		rsyserr(FLOG, errno, "fstat(%s)", fname);
 		ok = 0;
 	} else if (lp_strict_modes(module)) {
@@ -123,29 +124,30 @@
 		}
 	}
 	if (!ok) {
-		close(fd);
+		fclose(fh);
 		return "ignoring secrets file";
 	}
 
 	if (*user == '#') {
 		/* Reject attempt to match a comment. */
-		close(fd);
+		fclose(fh);
 		return "invalid username";
 	}
 
 	/* Try to find a line that starts with the user (or @group) name and a ':'. */
 	err = "secret not found";
-	while ((user || group) && read_line_old(fd, line, sizeof line, 1)) {
-		const char **ptr, *s;
+	while ((user || group) && fgets(line, sizeof line, fh) != NULL) {
+		const char **ptr, *s = strtok(line, "\n\r");
 		int len;
-		if (*line == '@') {
+		if (!s)
+			continue;
+		if (*s == '@') {
 			ptr = &group;
 			len = group_len;
-			s = line+1;
+			s++;
 		} else {
 			ptr = &user;
 			len = user_len;
-			s = line;
 		}
 		if (!*ptr || strncmp(s, *ptr, len) != 0 || s[len] != ':')
 			continue;
@@ -158,7 +160,7 @@
 		*ptr = NULL; /* Don't look for name again. */
 	}
 
-	close(fd);
+	fclose(fh);
 
 	memset(line, 0, sizeof line);
 	memset(pass2, 0, sizeof pass2);
