$NetBSD: patch-solaris_SolarisProcess.c,v 1.1 2024/02/26 09:31:52 nia Exp $

PR created upstream:

https://github.com/htop-dev/htop/pull/1371

From 4b87af0663f83ed90f044f975e519409c92b8bd9 Mon Sep 17 00:00:00 2001
From: Dominik Hassler <hadfl@omnios.org>
Date: Thu, 11 Jan 2024 17:44:34 +0000
Subject: [PATCH] fixes for illumos/Solaris platforms

--- solaris/SolarisProcess.c.orig	2024-01-10 09:54:15.000000000 +0000
+++ solaris/SolarisProcess.c
@@ -15,7 +15,6 @@ in the source distribution for its full 
 #include <unistd.h>
 #include <sys/syscall.h>
 
-#include "Process.h"
 #include "ProcessTable.h"
 #include "CRT.h"
 
