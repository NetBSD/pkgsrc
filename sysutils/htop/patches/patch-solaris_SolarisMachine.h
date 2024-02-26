$NetBSD: patch-solaris_SolarisMachine.h,v 1.1 2024/02/26 09:31:52 nia Exp $

PR created upstream:

https://github.com/htop-dev/htop/pull/1371

From 4b87af0663f83ed90f044f975e519409c92b8bd9 Mon Sep 17 00:00:00 2001
From: Dominik Hassler <hadfl@omnios.org>
Date: Thu, 11 Jan 2024 17:44:34 +0000
Subject: [PATCH] fixes for illumos/Solaris platforms

--- solaris/SolarisMachine.h.orig	2024-01-10 09:54:15.000000000 +0000
+++ solaris/SolarisMachine.h
@@ -19,6 +19,7 @@ in the source distribution for its full 
 #include <sys/uio.h>
 
 #include "Hashtable.h"
+#include "Machine.h"
 #include "UsersTable.h"
 
 #include "zfs/ZfsArcStats.h"
