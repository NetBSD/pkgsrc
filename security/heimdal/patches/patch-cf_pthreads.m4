$NetBSD: patch-cf_pthreads.m4,v 1.1 2013/07/26 12:40:06 ryoon Exp $

* GNU/kFreeBSD parts: use host of Debian GNU/kFreeBSD 7.0.

--- cf/pthreads.m4.orig	2012-01-10 21:53:51.000000000 +0000
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
