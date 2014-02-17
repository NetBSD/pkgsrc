$NetBSD: patch-src_collectd.c,v 1.1 2014/02/17 11:21:55 fhajny Exp $

sg_init() expects an arg.
--- src/collectd.c.orig	2014-01-26 08:09:14.840391576 +0000
+++ src/collectd.c
@@ -288,7 +288,7 @@ static int do_init (void)
 #endif
 
 #if HAVE_LIBSTATGRAB
-	if (sg_init ())
+	if (sg_init (0))
 	{
 		ERROR ("sg_init: %s", sg_str_error (sg_get_error ()));
 		return (-1);
