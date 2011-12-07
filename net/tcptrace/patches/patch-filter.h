$NetBSD: patch-filter.h,v 1.1 2011/12/07 15:18:51 joerg Exp $

--- filter.h.orig	2003-11-19 14:38:06.000000000 +0000
+++ filter.h
@@ -118,7 +118,7 @@ enum optype {
 union Constant {
     u_llong	u_longint;
     llong	longint;
-    Bool	bool;
+    Bool	boolean;
     char	*string;
     ipaddr	*pipaddr;
 };
