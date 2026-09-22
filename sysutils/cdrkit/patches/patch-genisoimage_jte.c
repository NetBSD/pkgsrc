$NetBSD: patch-genisoimage_jte.c,v 1.1 2026/09/22 08:05:41 ryoon Exp $

--- genisoimage/jte.c.orig	2026-08-22 08:59:42.552750494 +0000
+++ genisoimage/jte.c
@@ -32,6 +32,7 @@
 #include <ctype.h>
 #endif
 
+#include "md5.h"
 #ifdef	VMS
 #include "vms.h"
 #endif
