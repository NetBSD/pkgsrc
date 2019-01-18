$NetBSD: patch-uidswap.c,v 1.6 2019/01/18 20:13:37 tnn Exp $

Interix support

--- uidswap.c.orig	2018-10-17 00:01:20.000000000 +0000
+++ uidswap.c
@@ -68,13 +68,13 @@ temporarily_use_uid(struct passwd *pw)
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
@@ -98,10 +98,11 @@ temporarily_use_uid(struct passwd *pw)
 
 	/* set and save the user's groups */
 	if (user_groupslen == -1 || user_groups_uid != pw->pw_uid) {
+#ifndef HAVE_INTERIX
 		if (initgroups(pw->pw_name, pw->pw_gid) < 0)
 			fatal("initgroups: %s: %.100s", pw->pw_name,
 			    strerror(errno));
-
+#endif
 		user_groupslen = getgroups(0, NULL);
 		if (user_groupslen < 0)
 			fatal("getgroups: %.100s", strerror(errno));
@@ -116,9 +117,11 @@ temporarily_use_uid(struct passwd *pw)
 		}
 		user_groups_uid = pw->pw_uid;
 	}
+#ifndef HAVE_INTERIX
 	/* Set the effective uid to the given (unprivileged) uid. */
 	if (setgroups(user_groupslen, user_groups) < 0)
 		fatal("setgroups: %.100s", strerror(errno));
+#endif
 #ifndef SAVED_IDS_WORK_WITH_SETEUID
 	/* Propagate the privileged gid to all of our gids. */
 	if (setgid(getegid()) < 0)
@@ -166,8 +169,10 @@ restore_uid(void)
 	setgid(getgid());
 #endif /* SAVED_IDS_WORK_WITH_SETEUID */
 
+#ifndef HAVE_INTERIX
 	if (setgroups(saved_egroupslen, saved_egroups) < 0)
 		fatal("setgroups: %.100s", strerror(errno));
+#endif
 	temporarily_use_uid_effective = 0;
 }
 
@@ -190,6 +195,10 @@ permanently_set_uid(struct passwd *pw)
 	debug("permanently_set_uid: %u/%u", (u_int)pw->pw_uid,
 	    (u_int)pw->pw_gid);
 
+#if defined(HAVE_INTERIX)
+	if (setuser(pw->pw_name, NULL, SU_COMPLETE))
+		fatal("setuser %u: %.100s", (u_int)pw->pw_gid, strerror(errno));
+#else
 	if (setresgid(pw->pw_gid, pw->pw_gid, pw->pw_gid) < 0)
 		fatal("setresgid %u: %.100s", (u_int)pw->pw_gid, strerror(errno));
 
@@ -226,6 +235,7 @@ permanently_set_uid(struct passwd *pw)
 	    (setuid(old_uid) != -1 || seteuid(old_uid) != -1))
 		fatal("%s: was able to restore old [e]uid", __func__);
 #endif
+#endif /* HAVE_INTERIX */
 
 	/* Verify UID drop was successful */
 	if (getuid() != pw->pw_uid || geteuid() != pw->pw_uid) {
