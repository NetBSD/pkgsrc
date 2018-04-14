$NetBSD: patch-Drivers_nn_yyparse.c,v 1.1 2018/04/14 08:26:34 adam Exp $

Fix building.

--- Drivers/nn/yyparse.c.orig	2018-04-14 08:14:33.000000000 +0000
+++ Drivers/nn/yyparse.c
@@ -82,7 +82,7 @@
 static	char	sccsid[]
 	= "@(#)SQL parser for NNSQL(NetNews SQL), Copyright(c) 1995, 1996 by Ke Jin";
 
-#include	<config.h>
+#include	"nnconfig.h"
 
 #include	<nncol.h>
 #include	<yyenv.h>
