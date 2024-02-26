$NetBSD: patch-solaris_SolarisMachine.c,v 1.1 2024/02/26 09:31:52 nia Exp $

PR created upstream:

https://github.com/htop-dev/htop/pull/1371

From 4b87af0663f83ed90f044f975e519409c92b8bd9 Mon Sep 17 00:00:00 2001
From: Dominik Hassler <hadfl@omnios.org>
Date: Thu, 11 Jan 2024 17:44:34 +0000
Subject: [PATCH] fixes for illumos/Solaris platforms

--- solaris/SolarisMachine.c.orig	2024-01-10 09:54:15.000000000 +0000
+++ solaris/SolarisMachine.c
@@ -57,7 +57,7 @@ static void SolarisMachine_updateCPUcoun
 
    if (s != super->activeCPUs) {
       change = true;
-      hsuper->activeCPUs = s;
+      super->activeCPUs = s;
    }
 
    if (change) {
@@ -310,6 +310,10 @@ Machine* Machine_new(UsersTable* usersTa
       CRT_fatalError("Cannot get pagesize by sysconf(_SC_PAGESIZE)");
    this->pageSizeKB = this->pageSize / 1024;
 
+   this->kd = kstat_open();
+   if (!this->kd)
+      CRT_fatalError("Cannot open kstat handle");
+
    SolarisMachine_updateCPUcount(this);
 
    return super;
