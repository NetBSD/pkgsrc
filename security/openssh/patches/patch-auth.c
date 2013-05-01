$NetBSD: patch-auth.c,v 1.1 2013/05/01 19:58:26 imil Exp $

Replace uid 0 with ROOTUID macro

--- auth.c.orig	2013-03-12 00:31:05.000000000 +0000
+++ auth.c
@@ -385,7 +385,7 @@ check_key_in_hostfiles(struct passwd *pw
 		user_hostfile = tilde_expand_filename(userfile, pw->pw_uid);
 		if (options.strict_modes &&
 		    (stat(user_hostfile, &st) == 0) &&
-		    ((st.st_uid != 0 && st.st_uid != pw->pw_uid) ||
+		    ((st.st_uid != ROOTUID && st.st_uid != pw->pw_uid) ||
 		    (st.st_mode & 022) != 0)) {
 			logit("Authentication refused for %.100s: "
 			    "bad owner or modes for %.200s",
