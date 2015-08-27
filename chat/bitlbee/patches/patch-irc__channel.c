$NetBSD: patch-irc__channel.c,v 1.1 2015/08/27 21:58:42 wiz Exp $

From b6a3fbf3b94d1e7e7aee82375661fc0934fec48b Mon Sep 17 00:00:00 2001
From: dequis <dx@dxzone.com.ar>
Date: Thu, 27 Aug 2015 04:25:07 -0300
Subject: [PATCH] irc_channel_name_gen: handle g_convert_with_fallback failures

First fallback to ASCII without TRANSLIT, and if that fails too, just
give up by returning NULL.

Basically the same thing as 3a27896 (a netbsd specific fix), but for
channel names. This wasn't needed before because the older version of
this code caught the NULL from the ASCII//TRANSLIT attempt and gave up
immediately, while the refactored version lacked null checking.
---
 irc_channel.c | 10 ++++++++++
 1 file changed, 10 insertions(+)

diff --git a/irc_channel.c b/irc_channel.c
index 3de68e3..cbd306a 100644
--- irc_channel.c.orig	2015-06-16 22:30:40.000000000 +0000
+++ irc_channel.c
@@ -592,6 +592,16 @@ char *irc_channel_name_gen(irc_t *irc, c
 	gsize bytes_written;
 
 	translit_name = g_convert_with_fallback(hint, -1, "ASCII//TRANSLIT", "UTF-8", "", NULL, &bytes_written, NULL);
+
+      if (!translit_name) {
+              /* Same thing as in nick_gen() in nick.c, try again without //TRANSLIT */
+              translit_name = g_convert_with_fallback(hint, -1, "ASCII", "UTF-8", "", NULL, &bytes_written, NULL);
+      }
+
+      if (!translit_name) {
+              return NULL;
+      }
+
 	if (bytes_written > MAX_NICK_LENGTH) {
 		translit_name[MAX_NICK_LENGTH] = '\0';
 	}
