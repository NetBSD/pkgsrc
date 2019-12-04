$NetBSD: patch-src_common_modes.c,v 1.1 2019/12/04 11:57:05 nia Exp $

Fixes a message parser bug.

https://github.com/hexchat/hexchat/commit/804f959a1d0c9bfe88166a7541af4371460b468b.patch

--- src/common/modes.c.orig	2018-08-29 21:13:25.000000000 +0000
+++ src/common/modes.c
@@ -735,6 +735,8 @@ handle_mode (server * serv, char *word[]
 		if (!(*word[i + offset]))
 			break;
 		num_args++;
+		if (word[i + offset][0] == ':')
+			break;
 	}
 
 	/* count the number of modes (without the -/+ chars */
@@ -765,7 +767,7 @@ handle_mode (server * serv, char *word[]
 			if ((all_modes_have_args || mode_has_arg (serv, sign, *modes)) && arg < (num_args + 1))
 			{
 				arg++;
-				argstr = word[arg + offset];
+				argstr = STRIP_COLON(word, word_eol, arg+offset);
 			}
 			handle_single_mode (&mr, sign, *modes, nick, chan,
 									  argstr, numeric_324 || prefs.hex_irc_raw_modes,
