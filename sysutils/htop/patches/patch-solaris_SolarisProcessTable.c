$NetBSD: patch-solaris_SolarisProcessTable.c,v 1.1 2024/02/26 09:31:52 nia Exp $

PR created upstream:

https://github.com/htop-dev/htop/pull/1371

From 4b87af0663f83ed90f044f975e519409c92b8bd9 Mon Sep 17 00:00:00 2001
From: Dominik Hassler <hadfl@omnios.org>
Date: Thu, 11 Jan 2024 17:44:34 +0000
Subject: [PATCH] fixes for illumos/Solaris platforms

--- solaris/SolarisProcessTable.c.orig	2024-01-10 09:54:15.000000000 +0000
+++ solaris/SolarisProcessTable.c
@@ -24,6 +24,7 @@ in the source distribution for its full 
 
 #include "CRT.h"
 #include "solaris/Platform.h"
+#include "solaris/SolarisMachine.h"
 #include "solaris/SolarisProcess.h"
 
 
@@ -112,8 +113,8 @@ static int SolarisProcessTable_walkproc(
 
    // Setup process list
    ProcessTable* pt = (ProcessTable*) listptr;
-   SolarisProcessTable* spt = (SolarisProcessTable*) listptr;
-   Machine* host = pt->host;
+   const Machine* host = pt->super.host;
+   const SolarisMachine* shost = (const SolarisMachine*) host;
 
    id_t lwpid_real = _lwpsinfo->pr_lwpid;
    if (lwpid_real > 1023) {
@@ -133,7 +134,7 @@ static int SolarisProcessTable_walkproc(
    const Settings* settings = host->settings;
 
    // Common code pass 1
-   proc->show               = false;
+   proc->super.show         = false;
    sproc->taskid            = _psinfo->pr_taskid;
    sproc->projid            = _psinfo->pr_projid;
    sproc->poolid            = _psinfo->pr_poolid;
@@ -171,7 +172,7 @@ static int SolarisProcessTable_walkproc(
       sproc->realpid        = _psinfo->pr_pid;
       sproc->lwpid          = lwpid_real;
       sproc->zoneid         = _psinfo->pr_zoneid;
-      sproc->zname          = SolarisProcessTable_readZoneName(spt->kd, sproc);
+      sproc->zname          = SolarisProcessTable_readZoneName(shost->kd, sproc);
       SolarisProcessTable_updateExe(_psinfo->pr_pid, proc);
 
       Process_updateComm(proc, _psinfo->pr_fname);
@@ -218,7 +219,7 @@ static int SolarisProcessTable_walkproc(
             pt->totalTasks += proc->nlwp + 1;
          }
       }
-      proc->show = !(settings->hideKernelThreads && proc->isKernelThread);
+      proc->super.show = !(settings->hideKernelThreads && proc->isKernelThread);
    } else { // We are not in the master LWP, so jump to the LWP handling code
       proc->percent_cpu        = ((uint16_t)_lwpsinfo->pr_pctcpu / (double)32768) * (double)100.0;
       Process_updateCPUFieldWidths(proc->percent_cpu);
