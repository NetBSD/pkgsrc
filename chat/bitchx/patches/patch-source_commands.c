$NetBSD: patch-source_commands.c,v 1.1 2024/03/16 13:11:55 nia Exp $

Remove duplicate symbols. From Fedora Linux.

--- source/commands.c.orig	2014-11-04 10:54:23.000000000 +0000
+++ source/commands.c
@@ -118,7 +118,6 @@ extern	int	doing_notice;
 
 static	void	oper_password_received (char *, char *);
 
-int	no_hook_notify = 0;
 int	load_depth = -1;
 
 extern char	cx_function[];
