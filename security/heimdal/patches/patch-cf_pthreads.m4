$NetBSD: patch-cf_pthreads.m4,v 1.2 2015/07/11 04:26:57 rodent Exp $

* GNU/kFreeBSD parts: use host of Debian GNU/kFreeBSD 7.0.

--- cf/pthreads.m4.orig	2012-12-09 22:06:44.000000000 +0000
+++ cf/pthreads.m4
@@ -48,7 +48,7 @@ case "$host" in 
 		;;
 	esac
 	;;
-*-*-kfreebsd*-gnu*)
+*-*-kfreebsd*-gnu*|*-*-gnukfreebsd*)
 	native_pthread_support=yes
 	PTHREAD_CFLAGS=-pthread
 	PTHREAD_LIBADD=-pthread
