--- findcc.c.orig	2013-10-09 17:38:38.000000000 +0300
+++ findcc.c	2013-12-08 17:33:49.000000000 +0300
@@ -34,12 +34,6 @@
 #endif
 
 #include <sys/cdefs.h>
-#if !defined(lint)
-__COPYRIGHT("@(#) Copyright (c) 1999 The NetBSD Foundation, Inc.\
- All rights reserved.");
-__RCSID("$NetBSD: patch-findcc.c,v 1.1 2013/12/08 15:22:23 cheusov Exp $");
-#endif /* not lint */
-
 #include <sys/param.h>
 #include <stdio.h>
 #include <stdlib.h>
