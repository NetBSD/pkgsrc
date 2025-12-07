$NetBSD: patch-doas.c,v 1.3 2025/12/07 12:21:56 vins Exp $

Backport commit from OpenBSD/src, which attempts to make doas more
resistant to rowhammer attacks.
https://github.com/openbsd/src/commit/38599afa1d1d1f14a897b01350e8ce94486e1788

--- doas.c.orig	2025-12-07 11:59:21.090136657 +0000
+++ doas.c
@@ -148,6 +148,8 @@ permit(uid_t uid, gid_t *groups, int ngr
 			*lastr = rules[i];
 	}
 	if (!*lastr)
+		return -1;
+	if ((*lastr)->action == PERMIT)
 		return 0;
 	return (*lastr)->action == PERMIT;
 }
@@ -184,6 +186,7 @@ checkconfig(const char *confpath, int ar
     uid_t uid, gid_t *groups, int ngroups, uid_t target)
 {
 	const struct rule *rule;
+	int rv;
 
 	if (setresuid(uid, uid, uid) != 0)
 		err(1, "setresuid");
@@ -192,8 +195,9 @@ checkconfig(const char *confpath, int ar
 	if (!argc)
 		exit(0);
 
-	if (permit(uid, groups, ngroups, &rule, target, argv[0],
-	    (const char **)argv + 1)) {
+	rv = permit(uid, groups, ngroups, &rule, target, argv[0],
+ 		(const char **)argv + 1);
+	if (rv == 0) {
 		printf("permit%s\n", (rule->options & NOPASS) ? " nopass" : "");
 		exit(0);
 	} else {
@@ -347,8 +351,9 @@ main(int argc, char **argv)
 	}
 
 	cmd = argv[0];
-	if (!permit(uid, groups, ngroups, &rule, target, cmd,
-	    (const char **)argv + 1)) {
+	rv = permit(uid, groups, ngroups, &rule, target, cmd,
+	(const char **)argv + 1);
+	if (rv != 0) {
 		syslog(LOG_AUTHPRIV | LOG_NOTICE,
 		    "command not permitted for %s: %s", mypw->pw_name, cmdline);
 		errc(1, EPERM, NULL);
