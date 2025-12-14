$NetBSD: patch-usr.sbin_smtpd_smtp__session.c,v 1.1.18.1 2025/12/14 20:03:58 maya Exp $

Add a patch to handle long usernames during SMTP authentication.

--- usr.sbin/smtpd/smtp_session.c.orig	2025-07-30 20:26:49.764391744 +0000
+++ usr.sbin/smtpd/smtp_session.c
@@ -80,6 +80,7 @@ enum {
 	TX_ERROR_ENVELOPE,
 	TX_ERROR_SIZE,
 	TX_ERROR_IO,
+	SF_USERTOOLONG		= 0x0400,
 	TX_ERROR_LOOP,
 	TX_ERROR_MALFORMED,
 	TX_ERROR_RESOURCES,
@@ -962,6 +963,15 @@ smtp_session_imsg(struct mproc *p, struc
 
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
 			log_info("%016"PRIx64" smtp "
 			    "authentication user=%s "
@@ -1964,7 +1974,7 @@ smtp_rfc4954_auth_plain(struct smtp_sess
 		/* String is not NUL terminated, leave room. */
 		if ((len = base64_decode(arg, (unsigned char *)buf,
 			    sizeof(buf) - 1)) == -1)
-			goto abort;
+			s->flags |= SF_USERTOOLONG;
 		/* buf is a byte string, NUL terminate. */
 		buf[len] = '\0';
 
@@ -2021,9 +2031,12 @@ smtp_rfc4954_auth_login(struct smtp_sess
 
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
