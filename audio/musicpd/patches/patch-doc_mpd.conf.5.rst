$NetBSD: patch-doc_mpd.conf.5.rst,v 1.2 2026/01/30 08:58:13 wiz Exp $

Fix the sysconfdir path.

--- doc/mpd.conf.5.rst.orig	2026-01-26 13:50:08.000000000 +0000
+++ doc/mpd.conf.5.rst
@@ -10,7 +10,7 @@ ------------
 
 :file:`mpd.conf` is the configuration file for :manpage:`mpd(1)`.
 
-Usually, that is :file:`/etc/mpd.conf`, unless a different path is
+Usually, that is :file:`@PKG_SYSCONFDIR@/etc/mpd.conf`, unless a different path is
 specified on the command line.
 
 If you run :program:`MPD` as a user daemon (and not as a system
@@ -294,7 +294,7 @@ -----
 :file:`$XDG_CONFIG_HOME/mpd/mpd.conf`
   User configuration file (usually :file:`~/.config/mpd/mpd.conf`).
 
-:file:`/etc/mpd.conf`
+:file:`@PKG_SYSCONFDIR@/etc/mpd.conf`
   Global configuration file.
 
 See Also
