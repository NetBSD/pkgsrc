$NetBSD: patch-src_mkinclud.mak,v 1.1 2022/12/28 15:20:03 wiz Exp $

Fix installation for icon and desktop file.
Sent upstream via email.

--- src/mkinclud.mak.orig	2022-12-21 03:55:22.000000000 +0000
+++ src/mkinclud.mak
@@ -693,8 +693,8 @@ installscript=$(INSTALLBIN)
 installdesktop=$(INSTALL)
 desktop=../usrshare/setup_install/mined.desktop
 icon=../usrshare/setup_install/mined.xpm
-rootmenudir=$(DESTDIR)$(root)/usr/share/applications
-rooticondir=$(DESTDIR)$(root)/usr/share/pixmaps
+rootmenudir=$(DESTDIR)$(root)$(prefix)/share/applications
+rooticondir=$(DESTDIR)$(root)$(prefix)/share/pixmaps
 localmenudir=$(DESTDIR)$(root)/usr/local/share/applications
 localicondir=$(DESTDIR)$(root)/usr/local/share/pixmaps
 usermenudir=${HOME}/.local/share/applications
