$NetBSD: patch-usr.sbin_smtpd_smtp__session.c,v 1.1 2023/08/24 15:26:40 vins Exp $

Add a patch to handle long usernames during SMTP authentication,
e.g. often username exceeds the limit when it contains @host.name
part.

From FreeBSD's ports.

cf.http://svnweb.freebsd.org/ports?view=revision&revision=394424

For update 6.7.1p1:
Removed hunk to increase buffersize to LOGIN_NAME_MAX+HOST_NAME_MAX+1,
this was already increased upstream to SMTPD_MAXMAILADDRSIZE.

--- usr.sbin/smtpd/smtp_session.c.orig	2020-05-21 19:06:04.000000000 +0000
+++ usr.sbin/smtpd/smtp_session.c
@@ -84,6 +84,7 @@ enum {
 	TX_ERROR_ENVELOPE,
 	TX_ERROR_SIZE,
 	TX_ERROR_IO,
+	SF_USERTOOLONG		= 0x0400,
 	TX_ERROR_LOOP,
 	TX_ERROR_MALFORMED,
 	TX_ERROR_RESOURCES,
@@ -970,6 +971,15 @@ smtp_session_imsg(struct mproc *p, struc
 
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
@@ -1967,7 +1977,7 @@ smtp_rfc4954_auth_plain(struct smtp_sess
 		user++; /* skip NUL */
 		if (strlcpy(s->username, user, sizeof(s->username))
 		    >= sizeof(s->username))
-			goto abort;
+			s->flags |= SF_USERTOOLONG;
 
 		pass = memchr(user, '\0', len - (user - buf));
 		if (pass == NULL || pass >= buf + len - 2)
@@ -2011,9 +2021,12 @@ smtp_rfc4954_auth_login(struct smtp_sess
 
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
