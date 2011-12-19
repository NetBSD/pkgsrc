$NetBSD: patch-outgoing_tn.c,v 1.1 2011/12/19 13:25:22 wiz Exp $

Add missing header files (for cleanup()).

--- outgoing/tn.c.orig	1996-09-10 00:58:34.000000000 +0000
+++ outgoing/tn.c
@@ -49,6 +49,8 @@ static char sccsid[] = "@(#)telnetd.c	8.
 
 #include "tndefs.h"
 #include "tnext.h"
+#include "cdefs.h"
+#include "global.h"
 
 int	secflag;
 char	tty_dev[16];
