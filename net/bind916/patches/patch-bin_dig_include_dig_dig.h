$NetBSD: patch-bin_dig_include_dig_dig.h,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- bin/dig/include/dig/dig.h.orig	2020-05-06 09:59:35.000000000 +0000
+++ bin/dig/include/dig/dig.h
@@ -230,7 +230,7 @@ extern bool		 free_now;
 extern bool		 debugging, debugtiming, memdebugging;
 extern bool		 keep_open;
 
-extern char *progname;
+extern const char *progname;
 extern int   tries;
 extern int   fatalexit;
 extern bool  verbose;
