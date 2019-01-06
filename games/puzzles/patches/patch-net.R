$NetBSD: patch-net.R,v 1.1 2019/01/06 20:37:14 rillig Exp $

Rename 'net' to 'netgame' (like on Windows) to avoid a conflict with
net/samba and net/samba4.

--- net.R.orig	2018-12-12 22:18:00.000000000 +0000
+++ net.R
@@ -2,7 +2,7 @@
 
 NET_EXTRA = tree234 dsf findloop
 
-net      : [X] GTK COMMON net NET_EXTRA net-icon|no-icon
+netgame  : [X] GTK COMMON net NET_EXTRA net-icon|no-icon
 
 # The Windows Net shouldn't be called `net.exe' since Windows
 # already has a reasonably important utility program by that name!
@@ -11,7 +11,7 @@ netgame  : [G] WINDOWS COMMON net NET_EX
 ALL += net[COMBINED] NET_EXTRA
 
 !begin am gtk
-GAMES += net
+GAMES += netgame
 !end
 
 !begin >list.c
