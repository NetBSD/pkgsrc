$NetBSD: patch-src_common_proto-irc.h,v 1.1 2019/12/04 11:57:05 nia Exp $

Fixes a message parser bug.

https://github.com/hexchat/hexchat/commit/804f959a1d0c9bfe88166a7541af4371460b468b.patch

--- src/common/proto-irc.h.orig	2018-08-29 21:13:25.000000000 +0000
+++ src/common/proto-irc.h
@@ -28,6 +28,8 @@
 		(time_t)0, /* timestamp */		\
 	}
 
+#define STRIP_COLON(word, word_eol, idx) (word)[(idx)][0] == ':' ? (word_eol)[(idx)]+1 : (word)[(idx)]
+
 /* Message tag information that might be passed along with a server message
  *
  * See http://ircv3.atheme.org/specification/capability-negotiation-3.1
