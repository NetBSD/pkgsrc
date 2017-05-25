$NetBSD: patch-ezmlm-dispatch.c,v 1.1 2017/05/25 20:41:27 schmonz Exp $

Fix Illumos build.

--- ezmlm-dispatch.c.orig	2014-05-15 02:54:21.000000000 +0000
+++ ezmlm-dispatch.c
@@ -4,6 +4,7 @@
 #include "env.h"
 #include "sender.h"
 #include "strerr.h"
+#include "sgetopt.h"
 #include "getconfopt.h"
 #include "substdio.h"
 #include "subfd.h"
