$NetBSD: patch-libxmms_xmmsctrl.c,v 1.1 2026/03/23 13:11:30 nia Exp $

Fix implicit declaration of memcpy(3), strcpy(3).

--- libxmms/xmmsctrl.c.orig	2026-03-23 12:08:59.075524353 +0000
+++ libxmms/xmmsctrl.c
@@ -30,6 +30,7 @@
 #include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <math.h>
 #include "xmmsctrl.h"
 #include "../xmms/controlsocket.h"
