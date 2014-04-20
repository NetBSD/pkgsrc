$NetBSD: patch-vtun.h,v 1.1 2014/04/20 21:03:25 adam Exp $

Fix for C99 standard.

--- vtun.h.orig	2014-04-20 20:52:19.000000000 +0000
+++ vtun.h
@@ -231,6 +231,6 @@ void client(struct vtun_host *host);
 int  tunnel(struct vtun_host *host);
 int  read_config(char *file);
 struct vtun_host * find_host(char *host);
-inline void clear_nat_hack_flags(int svr);
+void clear_nat_hack_flags(int svr);
 
 #endif
