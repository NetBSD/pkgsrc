$NetBSD: patch-orc_orccodemem.c,v 1.2 2022/11/08 12:10:18 wiz Exp $

Add missing include for errno(3).

https://gitlab.freedesktop.org/gstreamer/orc/-/merge_requests/81

--- orc/orccodemem.c.orig	2022-10-31 18:16:26.000000000 +0000
+++ orc/orccodemem.c
@@ -1,6 +1,7 @@
 
 #include "config.h"
 
+#include <errno.h>
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
