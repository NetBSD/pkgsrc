$NetBSD: patch-hints_netbsd.sh,v 1.1.2.2 2012/02/28 23:40:07 tron Exp $

* NetBSD-6.x is same condition as older releases.

--- hints/netbsd.sh.orig	2011-09-19 13:18:22.000000000 +0000
+++ hints/netbsd.sh
@@ -89,7 +89,7 @@ case "$osvers" in
 	;;
 esac
 case "$osvers" in
-0.9*|1.*|2.*|3.*|4.*|5.*)
+0.9*|1.*|2.*|3.*|4.*|5.*|6.*)
 	d_getprotoent_r="$undef"
 	d_getprotobyname_r="$undef"
 	d_getprotobynumber_r="$undef"
