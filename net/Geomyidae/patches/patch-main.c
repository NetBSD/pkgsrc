$NetBSD: patch-main.c,v 1.1 2018/09/21 17:10:57 leot Exp $

don't exit on SIGHUP

SIGHUP is normally often used in daemons to reload the config and/or reopen log
files.

This was noticed on OpenBSD not starting the geomyidae server on boot.  The
init implementations on OpenBSD, NetBSD and possibly others send SIGHUP to
processes in a boot transition period.

Backport from upstream commit 8d9bad389a4ac22fc292f92d0128af8679e640fa.

--- main.c.orig	2018-06-29 19:21:00.000000000 +0000
+++ main.c
@@ -256,7 +256,6 @@ sighandler(int sig)
 	case SIGCHLD:
 		while (waitpid(-1, NULL, WNOHANG) > 0);
 		break;
-	case SIGHUP:
 	case SIGINT:
 	case SIGQUIT:
 	case SIGABRT:
