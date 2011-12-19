$NetBSD: patch-outgoing_tnutil.c,v 1.1 2011/12/19 13:25:22 wiz Exp $

Add missing header files (for cleanup()).

--- outgoing/tnutil.c.orig	1996-04-30 07:02:50.000000000 +0000
+++ outgoing/tnutil.c
@@ -41,6 +41,8 @@ static char sccsid[] = "@(#)utility.c	8.
 #define PRINTOPTIONS
 #include "tndefs.h"
 #include "tnext.h"
+#include "cdefs.h"
+#include "global.h"
 
 /*
  * utility functions performing io related tasks
