$NetBSD: patch-uidswap.c,v 1.3.12.1 2015/08/24 19:06:40 tron Exp $

Interix support

--- uidswap.c.orig	2015-07-01 02:35:31.000000000 +0000
+++ uidswap.c
@@ -67,13 +67,13 @@ temporarily_use_uid(struct passwd *pw)
 	    (u_int)pw->pw_uid, (u_int)pw->pw_gid,
 	    (u_int)saved_euid, (u_int)saved_egid);
 #ifndef HAVE_CYGWIN
-	if (saved_euid != 0) {
+	if (saved_euid != ROOTUID) {
 		privileged = 0;
 		return;
 	}
 #endif
 #else
-	if (geteuid() != 0) {
+	if (geteuid() != ROOTUID) {
 		privileged = 0;
 		return;
 	}
@@ -96,9 +96,11 @@ temporarily_use_uid(struct passwd *pw)
 
 	/* set and save the user's groups */
 	if (user_groupslen == -1) {
+#ifndef HAVE_INTERIX
 		if (initgroups(pw->pw_name, pw->pw_gid) < 0)
 			fatal("initgroups: %s: %.100s", pw->pw_name,
 			    strerror(errno));
+#endif
 
 		user_groupslen = getgroups(0, NULL);
 		if (user_groupslen < 0)
@@ -112,9 +114,11 @@ temporarily_use_uid(struct passwd *pw)
 			free(user_groups);
 		}
 	}
+#ifndef HAVE_INTERIX
 	/* Set the effective uid to the given (unprivileged) uid. */
 	if (setgroups(user_groupslen, user_groups) < 0)
 		fatal("setgroups: %.100s", strerror(errno));
+#endif
 #ifndef SAVED_IDS_WORK_WITH_SETEUID
 	/* Propagate the privileged gid to all of our gids. */
 	if (setgid(getegid()) < 0)
@@ -187,8 +191,10 @@ restore_uid(void)
 	setgid(getgid());
 #endif /* SAVED_IDS_WORK_WITH_SETEUID */
 
+#ifndef HAVE_INTERIX
 	if (setgroups(saved_egroupslen, saved_egroups) < 0)
 		fatal("setgroups: %.100s", strerror(errno));
+#endif
 	temporarily_use_uid_effective = 0;
 }
 
@@ -211,6 +217,10 @@ permanently_set_uid(struct passwd *pw)
 	debug("permanently_set_uid: %u/%u", (u_int)pw->pw_uid,
 	    (u_int)pw->pw_gid);
 
+#if defined(HAVE_INTERIX)
+	if (setuser(pw->pw_name, NULL, SU_COMPLETE))
+		fatal("setuser %u: %.100s", (u_int)pw->pw_gid, strerror(errno));
+#else
 	if (setresgid(pw->pw_gid, pw->pw_gid, pw->pw_gid) < 0)
 		fatal("setresgid %u: %.100s", (u_int)pw->pw_gid, strerror(errno));
 
@@ -247,6 +257,7 @@ permanently_set_uid(struct passwd *pw)
 	    (setuid(old_uid) != -1 || seteuid(old_uid) != -1))
 		fatal("%s: was able to restore old [e]uid", __func__);
 #endif
+#endif /* HAVE_INTERIX */
 
 	/* Verify UID drop was successful */
 	if (getuid() != pw->pw_uid || geteuid() != pw->pw_uid) {
