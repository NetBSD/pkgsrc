$NetBSD: patch-command.h,v 1.2 2018/12/18 14:16:18 hauke Exp $

Fix for Radmind bug #221, accomodating for 64 bit time_t

--- command.h.orig	2010-12-13 03:42:49.000000000 +0000
+++ command.h
@@ -13,3 +13,5 @@ struct command {
     char	*c_name;
     int		(*c_func)( SNET *, int, char *[] );
 };
+
+#define RADMIND_STAT_FMT "%s %s %o %d %d %" PRItimet "d %" PRIofft "d %s\r\n"
