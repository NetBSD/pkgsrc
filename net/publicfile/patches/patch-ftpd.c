$NetBSD: patch-ftpd.c,v 1.2 2023/11/16 22:55:37 schmonz Exp $

Add missing includes.

--- ftpd.c.orig	1999-11-09 07:23:46.000000000 +0000
+++ ftpd.c
@@ -7,6 +7,7 @@
 #include "timeoutread.h"
 #include "timeoutwrite.h"
 #include "substdio.h"
+#include "exit.h"
 #include "fetch.h"
 #include "pathdecode.h"
 #include "file.h"
