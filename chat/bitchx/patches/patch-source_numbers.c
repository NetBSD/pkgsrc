$NetBSD: patch-source_numbers.c,v 1.1 2024/03/16 13:11:55 nia Exp $

Fix duplicate symbols, via Fedora Linux.

--- source/numbers.c.orig	2014-11-14 10:34:50.000000000 +0000
+++ source/numbers.c
@@ -66,7 +66,6 @@ void	show_server_map		(void);
 int	stats_k_grep		(char **);
 void	who_handlekill		(char *, char *, char *);
 void	handle_tracekill	(int, char *, char *, char *);
-int	no_hook_notify;
 extern  AJoinList *ajoin_list;
 void	remove_from_server_list (int);
 
