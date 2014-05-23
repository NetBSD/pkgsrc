$NetBSD: patch-src_gdbmtool.h,v 1.1 2014/05/23 20:49:37 wiz Exp $

Avoid conflict with sys/syslimits.h.

--- src/gdbmtool.h.orig	2013-05-15 15:32:42.000000000 +0000
+++ src/gdbmtool.h
@@ -138,7 +138,7 @@ struct kvpair *kvpair_list (struct locus
 #define ARG_STRING 0
 #define ARG_DATUM  1
 #define ARG_KVPAIR 2
-#define ARG_MAX    3
+#define GDBM_ARG_MAX    3
 
 /* Argument to a command handler */
 struct gdbmarg
