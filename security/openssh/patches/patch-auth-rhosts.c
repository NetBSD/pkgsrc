$NetBSD: patch-auth-rhosts.c,v 1.1 2013/05/01 19:58:26 imil Exp $

Replace uid 0 with ROOTUID macro

--- auth-rhosts.c.orig	2010-03-07 12:05:17.000000000 +0000
+++ auth-rhosts.c
@@ -230,7 +230,7 @@ auth_rhosts2_raw(struct passwd *pw, cons
 		return 0;
 
 	/* If not logging in as superuser, try /etc/hosts.equiv and shosts.equiv. */
-	if (pw->pw_uid != 0) {
+	if (pw->pw_uid != ROOTUID) {
 		if (check_rhosts_file(_PATH_RHOSTS_EQUIV, hostname, ipaddr,
 		    client_user, pw->pw_name)) {
 			auth_debug_add("Accepted for %.100s [%.100s] by /etc/hosts.equiv.",
@@ -256,7 +256,7 @@ auth_rhosts2_raw(struct passwd *pw, cons
 		return 0;
 	}
 	if (options.strict_modes &&
-	    ((st.st_uid != 0 && st.st_uid != pw->pw_uid) ||
+	    ((st.st_uid != ROOTUID && st.st_uid != pw->pw_uid) ||
 	    (st.st_mode & 022) != 0)) {
 		logit("Rhosts authentication refused for %.100s: "
 		    "bad ownership or modes for home directory.", pw->pw_name);
@@ -283,7 +283,7 @@ auth_rhosts2_raw(struct passwd *pw, cons
 		 * allowing access to their account by anyone.
 		 */
 		if (options.strict_modes &&
-		    ((st.st_uid != 0 && st.st_uid != pw->pw_uid) ||
+		    ((st.st_uid != ROOTUID && st.st_uid != pw->pw_uid) ||
 		    (st.st_mode & 022) != 0)) {
 			logit("Rhosts authentication refused for %.100s: bad modes for %.200s",
 			    pw->pw_name, buf);
