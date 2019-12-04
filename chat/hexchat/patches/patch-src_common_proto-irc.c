$NetBSD: patch-src_common_proto-irc.c,v 1.1 2019/12/04 11:57:05 nia Exp $

Fixes a message parser bug.

https://github.com/hexchat/hexchat/commit/804f959a1d0c9bfe88166a7541af4371460b468b.patch

--- src/common/proto-irc.c.orig	2018-08-29 21:13:25.000000000 +0000
+++ src/common/proto-irc.c
@@ -714,7 +714,7 @@ process_numeric (session * sess, int n,
 		break;
 
 	case 333:
-		inbound_topictime (serv, word[4], word[5], atol (word[6]), tags_data);
+		inbound_topictime (serv, word[4], word[5], atol (STRIP_COLON(word, word_eol, 6)), tags_data);
 		break;
 
 #if 0
@@ -726,7 +726,7 @@ process_numeric (session * sess, int n,
 #endif
 
 	case 341:						  /* INVITE ACK */
-		EMIT_SIGNAL_TIMESTAMP (XP_TE_UINVITE, sess, word[4], word[5],
+		EMIT_SIGNAL_TIMESTAMP (XP_TE_UINVITE, sess, word[4], STRIP_COLON(word, word_eol, 5),
 									  serv->servername, NULL, 0, tags_data->timestamp);
 		break;
 
@@ -1142,7 +1142,7 @@ process_named_msg (session *sess, char *
 		{
 
 		case WORDL('A','C','C','O'):
-			inbound_account (serv, nick, word[3], tags_data);
+			inbound_account (serv, nick, STRIP_COLON(word, word_eol, 3), tags_data);
 			return;
 
 		case WORDL('A', 'U', 'T', 'H'):
@@ -1150,7 +1150,7 @@ process_named_msg (session *sess, char *
 			return;
 
 		case WORDL('C', 'H', 'G', 'H'):
-			inbound_user_info (sess, NULL, word[3], word[4], NULL, nick, NULL,
+			inbound_user_info (sess, NULL, word[3], STRIP_COLON(word, word_eol, 4), NULL, nick, NULL,
 							   NULL, 0xff, tags_data);
 			return;
 
