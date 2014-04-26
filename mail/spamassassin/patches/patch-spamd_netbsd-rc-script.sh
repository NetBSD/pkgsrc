$NetBSD: patch-spamd_netbsd-rc-script.sh,v 1.1 2014/04/26 13:55:10 tron Exp $

Make an effort to pick up spamd_flags from the rc configuration when
not running on NetBSD/DragonFlyBSD.
Adjust comment for renamed file.

--- spamd/netbsd-rc-script.sh.orig	2014-02-07 08:36:38.000000000 +0000
+++ spamd/netbsd-rc-script.sh	2014-04-26 10:50:41.000000000 +0100
@@ -118,6 +118,12 @@
 
 else # not NetBSD or DragonFlyBSD
 
+	if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
+		load_rc_config $name
+	elif [ -f /etc/rc.conf ]; then
+		. /etc/rc.conf
+	fi
+
 	if [ -f ${pidfile} ];  then
 		the_spamd_pid=`head -1 ${pidfile}`
 	else
