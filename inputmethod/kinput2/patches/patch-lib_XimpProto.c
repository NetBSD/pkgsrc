$NetBSD: patch-lib_XimpProto.c,v 1.1 2011/09/13 07:28:48 mef Exp $

To compile with ja-freewnn-lib-1.11alpah22

--- lib/XimpProto.c.orig	2002-10-03 09:35:28.000000000 +0000
+++ lib/XimpProto.c
@@ -28,6 +28,7 @@ static char *rcsid = "$Id: XimpProto.c,v
 #include <X11/Xatom.h>
 #include <X11/Xmu/Atoms.h>
 #include <X11/Xmu/CharSet.h>
+#include <stdio.h>
 #include "XIMProto.h"
 #include "XimpProtoP.h"
 #include "ConvMgr.h"
