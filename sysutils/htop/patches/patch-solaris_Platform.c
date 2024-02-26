$NetBSD: patch-solaris_Platform.c,v 1.3 2024/02/26 09:31:52 nia Exp $

PR created upstream:

https://github.com/htop-dev/htop/pull/1371

From 4b87af0663f83ed90f044f975e519409c92b8bd9 Mon Sep 17 00:00:00 2001
From: Dominik Hassler <hadfl@omnios.org>
Date: Thu, 11 Jan 2024 17:44:34 +0000
Subject: [PATCH] fixes for illumos/Solaris platforms

--- solaris/Platform.c.orig	2024-01-10 09:54:15.000000000 +0000
+++ solaris/Platform.c
@@ -220,7 +220,7 @@ double Platform_setCPUValues(Meter* this
 
    v[CPU_METER_NICE]   = cpuData->nicePercent;
    v[CPU_METER_NORMAL] = cpuData->userPercent;
-   if (super->settings->detailedCPUTime) {
+   if (host->settings->detailedCPUTime) {
       v[CPU_METER_KERNEL]  = cpuData->systemPercent;
       v[CPU_METER_IRQ]     = cpuData->irqPercent;
       this->curItems = 4;
@@ -258,13 +258,13 @@ void Platform_setSwapValues(Meter* this)
 }
 
 void Platform_setZfsArcValues(Meter* this) {
-   const SolarisMachine* shost = (SolarisMachine*) this->host;
+   const SolarisMachine* shost = (const SolarisMachine*) this->host;
 
    ZfsArcMeter_readStats(this, &shost->zfs);
 }
 
 void Platform_setZfsCompressedArcValues(Meter* this) {
-   const SolarisMachine* shost = (SolarisMachine*) this->host;
+   const SolarisMachine* shost = (const SolarisMachine*) this->host;
 
    ZfsCompressedArcMeter_readStats(this, &shost->zfs);
 }
