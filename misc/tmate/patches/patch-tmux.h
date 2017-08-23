$NetBSD: patch-tmux.h,v 1.1 2017/08/23 18:56:14 jperkin Exp $

Allow override TMUX_CONF on the command line.

--- tmux.h.orig	2016-03-29 03:30:07.000000000 +0000
+++ tmux.h
@@ -53,7 +53,9 @@ struct tmuxpeer;
 struct tmuxproc;
 
 /* Default global configuration file. */
+#ifndef TMUX_CONF
 #define TMUX_CONF "/etc/tmux.conf"
+#endif
 
 /*
  * Minimum layout cell size, NOT including separator line. The scroll region
