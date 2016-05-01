$NetBSD: patch-smtpd_smtp__session.c,v 1.1 2016/05/01 05:56:40 mef Exp $

Add a patch to handle long usernames during SMTP authentication,
e.g. often username exceeds the limit when it contains @host.name
part.

From FreeBSD's ports.

cf.http://svnweb.freebsd.org/ports?view=revision&revision=394424

--- smtpd/smtp_session.c.orig	2016-02-02 07:40:06.000000000 +0000
+++ smtpd/smtp_session.c
@@ -84,6 +84,7 @@ enum session_flags {
 	SF_BADINPUT		= 0x0080,
 	SF_FILTERCONN		= 0x0100,
 	SF_FILTERDATA		= 0x0200,
+	SF_USERTOOLONG		= 0x0400,
 };
 
 enum message_flags {
@@ -133,7 +134,7 @@ struct smtp_session {
 
 	char			 helo[LINE_MAX];
 	char			 cmd[LINE_MAX];
-	char			 username[LOGIN_NAME_MAX];
+	char			 username[LOGIN_NAME_MAX+HOST_NAME_MAX+1];
 
 	struct envelope		 evp;
 
@@ -986,6 +987,15 @@ smtp_session_imsg(struct mproc *p, struc
 
 		s = tree_xpop(&wait_parent_auth, reqid);
 		strnvis(user, s->username, sizeof user, VIS_WHITE | VIS_SAFE);
+
+		if (s->flags & SF_USERTOOLONG) {
+			log_info("smtp-in: sesson %016"PRIx64
+				": auth failed because username too long",
+				s->id);
+			s->flags &= (~SF_USERTOOLONG);
+			success = LKA_PERMFAIL;
+		}
+
 		if (success == LKA_OK) {
 			log_info("smtp-in: session %016"PRIx64
 			    ": authentication successful for user %s ",
@@ -1925,7 +1935,7 @@ smtp_rfc4954_auth_plain(struct smtp_sess
 		user++; /* skip NUL */
 		if (strlcpy(s->username, user, sizeof(s->username))
 		    >= sizeof(s->username))
-			goto abort;
+			s->flags |= SF_USERTOOLONG;
 
 		pass = memchr(user, '\0', len - (user - buf));
 		if (pass == NULL || pass >= buf + len - 2)
@@ -1965,9 +1975,12 @@ smtp_rfc4954_auth_login(struct smtp_sess
 
 	case STATE_AUTH_USERNAME:
 		memset(s->username, 0, sizeof(s->username));
-		if (base64_decode(arg, (unsigned char *)s->username,
-				  sizeof(s->username) - 1) == -1)
+		if (base64_decode(arg, (unsigned char *)buf,
+				  sizeof(buf) - 1) == -1)
 			goto abort;
+		if (strlcpy(s->username, buf, sizeof(s->username))
+		    >= sizeof(s->username))
+			s->flags |= SF_USERTOOLONG;
 
 		smtp_enter_state(s, STATE_AUTH_PASSWORD);
 		smtp_reply(s, "334 UGFzc3dvcmQ6");
