$NetBSD: patch-auth.c,v 1.2.14.1 2015/07/14 22:03:39 tron Exp $

* Replace uid 0 with ROOTUID macro.
* Use login_getpwclass() instead of login_getclass() so that the root
  vs. default login class distinction is made correctly, from FrrrBSD's
  ports.

--- auth.c.orig	2015-07-01 02:35:31.000000000 +0000
+++ auth.c
@@ -422,7 +422,7 @@ check_key_in_hostfiles(struct passwd *pw
 		user_hostfile = tilde_expand_filename(userfile, pw->pw_uid);
 		if (options.strict_modes &&
 		    (stat(user_hostfile, &st) == 0) &&
-		    ((st.st_uid != 0 && st.st_uid != pw->pw_uid) ||
+		    ((st.st_uid != ROOTUID && st.st_uid != pw->pw_uid) ||
 		    (st.st_mode & 022) != 0)) {
 			logit("Authentication refused for %.100s: "
 			    "bad owner or modes for %.200s",
@@ -651,7 +651,7 @@ getpwnamallow(const char *user)
 	if (!allowed_user(pw))
 		return (NULL);
 #ifdef HAVE_LOGIN_CAP
-	if ((lc = login_getclass(pw->pw_class)) == NULL) {
+	if ((lc = login_getpwclass(pw)) == NULL) {
 		debug("unable to get login class: %s", user);
 		return (NULL);
 	}
