$NetBSD: patch-eph__cmd.c,v 1.1 2026/03/18 14:39:30 nia Exp $

Fix implicit declaration of string functions.

--- eph_cmd.c.orig	2001-08-28 06:28:01.000000000 +0000
+++ eph_cmd.c
@@ -89,6 +89,7 @@ static char *rcsid="$Id: eph_cmd.c,v 1.2
 #include "config.h"
 #endif
 #include <stdio.h>
+#include <string.h>
 #include "eph_io.h"
 #include "eph_priv.h"
 
