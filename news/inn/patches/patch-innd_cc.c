$NetBSD: patch-innd_cc.c,v 1.1 2013/11/27 10:02:55 spz Exp $

make sure the resulting type is long and not time_t, which would require
%lld with 64bit time_t.

--- innd/cc.c.orig	2012-06-15 18:25:36.000000000 +0000
+++ innd/cc.c
@@ -940,7 +940,7 @@ CCname(char *av[])
             mode = (cp->MaxCnx > 0 && cp->ActiveCnx == 0) ? "paused" : "";
             buffer_sprintf(&CCreply, true, ":%s:%ld:%s",
                            cp->State == CScancel ? "cancel" : "nntp",
-                           (long) Now.tv_sec - cp->LastActive, mode);
+                           (long) (Now.tv_sec - cp->LastActive), mode);
 	    break;
 	case CTlocalconn:
             buffer_sprintf(&CCreply, true, ":localconn::");
