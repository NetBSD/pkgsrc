$NetBSD: patch-outgoing_tnstate.c,v 1.1 2011/12/19 13:25:22 wiz Exp $

Add missing header files (for cleanup()).

--- outgoing/tnstate.c.orig	1996-04-30 07:02:49.000000000 +0000
+++ outgoing/tnstate.c
@@ -40,6 +40,8 @@ static char sccsid[] = "@(#)state.c	8.1 
 
 #include "tndefs.h"
 #include "tnext.h"
+#include "cdefs.h"
+#include "global.h"
 
 unsigned char	doopt[] = { IAC, DO, '%', 'c', 0 };
 unsigned char	dont[] = { IAC, DONT, '%', 'c', 0 };
