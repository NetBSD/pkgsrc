$NetBSD: patch-source_names.c,v 1.1 2018/07/19 22:22:21 mrg Exp $

fix a problem with reconnecting to the wrong window and also
join channels with the wrong key.

Index: source/names.c
===================================================================
RCS file: /home/cvs/ircii/source/names.c,v
retrieving revision 1.143
retrieving revision 1.144
diff -p -u -u -r1.143 -r1.144
--- source/names.c	4 Jul 2017 08:08:23 -0000	1.143
+++ source/names.c	6 Sep 2017 04:47:48 -0000	1.144
@@ -202,6 +202,8 @@ add_channel(u_char *channel, u_char *key
 		new->limit = 0;
 		do_add = 1;
 		full_list = server_get_chan_list(server);
+		if ((new->window = is_bound(channel, server)) == NULL)
+			new->window = curr_scr_win;
 		add_to_list((List **)(void *)&full_list, (List *) new);
 		server_set_chan_list(server, full_list);
 	}
