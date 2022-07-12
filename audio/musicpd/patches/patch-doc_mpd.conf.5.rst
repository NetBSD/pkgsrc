$NetBSD: patch-doc_mpd.conf.5.rst,v 1.1 2022/07/12 20:16:48 triaxx Exp $

Fix the sysconfdir path.

--- doc/mpd.conf.5.rst.orig	2022-07-08 23:05:38.000000000 +0000
+++ doc/mpd.conf.5.rst
@@ -9,7 +9,7 @@ DESCRIPTION
 :file:`mpd.conf` is the configuration file for :manpage:`mpd(1)`. If
 not specified on the command line, MPD first searches for it at
 :file:`$XDG_CONFIG_HOME/mpd/mpd.conf` then at :file:`~/.mpdconf` then
-at :file:`~/.mpd/mpd.conf` and then in :file:`/etc/mpd.conf`.
+at :file:`~/.mpd/mpd.conf` and then in :file:`@PKG_SYSCONFDIR@/etc/mpd.conf`.
 
 Each line in the configuration file contains a setting name and its value, e.g.:
 
@@ -184,7 +184,7 @@ FILES
 :file:`$XDG_CONFIG_HOME/mpd/mpd.conf`
   User configuration file (usually :file:`~/.config/mpd/mpd.conf`).
 
-:file:`/etc/mpd.conf`
+:file:`@PKG_SYSCONFDIR@/etc/mpd.conf`
   Global configuration file.
 
 SEE ALSO
