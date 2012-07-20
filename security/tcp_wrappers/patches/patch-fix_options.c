$NetBSD: patch-fix_options.c,v 1.1 2012/07/20 09:58:36 adam Exp $

Fix C error

--- fix_options.c.orig	2012-07-20 09:41:10.000000000 +0000
+++ fix_options.c
@@ -29,7 +29,7 @@ static char sccsid[] = "@(#) fix_options
 
 /* fix_options - get rid of IP-level socket options */
 
-fix_options(request)
+void fix_options(request)
 struct request_info *request;
 {
 #ifdef IP_OPTIONS
