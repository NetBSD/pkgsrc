$NetBSD: patch-include_asterisk_channel.h,v 1.1 2012/02/16 16:21:36 hans Exp $

--- include/asterisk/channel.h.orig	2006-11-07 19:22:01.000000000 +0100
+++ include/asterisk/channel.h	2012-01-25 13:58:47.328811938 +0100
@@ -1121,7 +1121,7 @@ static inline int ast_fdisset(struct pol
 	return 0;
 }
 
-#ifdef SOLARIS
+#if defined(SOLARIS) && !defined(timersub)
 static inline void timersub(struct timeval *tvend, struct timeval *tvstart, struct timeval *tvdiff)
 {
 	tvdiff->tv_sec = tvend->tv_sec - tvstart->tv_sec;
