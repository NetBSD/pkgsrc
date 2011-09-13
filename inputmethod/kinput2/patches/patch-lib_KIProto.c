$NetBSD: patch-lib_KIProto.c,v 1.1 2011/09/13 07:28:48 mef Exp $

To compile with ja-freewnn-lib-1.11alpah22

--- lib/KIProto.c.orig	2002-10-03 09:35:28.000000000 +0000
+++ lib/KIProto.c
@@ -23,6 +23,7 @@ static char *rcsid = "$Id: KIProto.c,v 1
 #include <X11/Xatom.h>
 #include <X11/Xmu/Atoms.h>
 #include <X11/Xmu/CharSet.h>
+#include <stdio.h>
 #include "KIProtoP.h"
 #include "ConvMgr.h"
 #include "OverConv.h"
