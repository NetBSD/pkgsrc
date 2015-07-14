$NetBSD: patch-auth-rhosts.c,v 1.1.18.1 2015/07/14 22:03:39 tron Exp $

Replace uid 0 with ROOTUID macro

--- auth-rhosts.c.orig	2015-07-01 02:35:31.000000000 +0000
+++ auth-rhosts.c
@@ -242,7 +242,7 @@ auth_rhosts2_raw(struct passwd *pw, cons
 	 * If not logging in as superuser, try /etc/hosts.equiv and
 	 * shosts.equiv.
 	 */
-	if (pw->pw_uid == 0)
+	if (pw->pw_uid == ROOTUID)
 		debug3("%s: root user, ignoring system hosts files", __func__);
 	else {
 		if (check_rhosts_file(_PATH_RHOSTS_EQUIV, hostname, ipaddr,
@@ -271,7 +271,7 @@ auth_rhosts2_raw(struct passwd *pw, cons
 		return 0;
 	}
 	if (options.strict_modes &&
-	    ((st.st_uid != 0 && st.st_uid != pw->pw_uid) ||
+	    ((st.st_uid != ROOTUID && st.st_uid != pw->pw_uid) ||
 	    (st.st_mode & 022) != 0)) {
 		logit("Rhosts authentication refused for %.100s: "
 		    "bad ownership or modes for home directory.", pw->pw_name);
@@ -298,7 +298,7 @@ auth_rhosts2_raw(struct passwd *pw, cons
 		 * allowing access to their account by anyone.
 		 */
 		if (options.strict_modes &&
-		    ((st.st_uid != 0 && st.st_uid != pw->pw_uid) ||
+		    ((st.st_uid != ROOTUID && st.st_uid != pw->pw_uid) ||
 		    (st.st_mode & 022) != 0)) {
 			logit("Rhosts authentication refused for %.100s: bad modes for %.200s",
 			    pw->pw_name, buf);
