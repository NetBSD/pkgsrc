$NetBSD: patch-src_snapshot__data.c,v 1.1 2026/02/16 13:51:42 gdt Exp $

Remediate setting of a feature define.

Reported upstream by email 20260216.

--- src/snapshot_data.c.orig	2026-02-16 00:20:59.000000000 +0000
+++ src/snapshot_data.c
@@ -1,4 +1,4 @@
-#define _XOPEN_SOURCE 700
+
 #include <unistd.h>
 #include "hamlib/config.h"
 #include "hamlib/rig.h"
