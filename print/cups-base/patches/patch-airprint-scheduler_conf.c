$NetBSD: patch-airprint-scheduler_conf.c,v 1.2 2019/11/17 21:22:03 leot Exp $

From bbc3507a260d29db3fc5601826f33c10f9dccd1e Mon Sep 17 00:00:00 2001
From: Till Kamppeter <till.kamppeter@gmail.com>
Date: Tue, 9 Aug 2016 18:11:29 +0200
Subject: Patch to support Apple AirPrint (printing from iPhone, iPad, iPod
 Touch to a CUPS server)

Bug-Ubuntu: https://bugs.launchpad.net/bugs/711779
Bug-Ubuntu: https://bugs.launchpad.net/bugs/1054495
Bug-Debian: http://bugs.debian.org/700961
Bug: https://cups.org/str.php?L4341
Last-Update: 2015-02-10

Patch-Name: airprint-support.patch
---
 conf/mime.convs.in   | 3 +++
 conf/mime.types      | 3 +++
 scheduler/conf.c     | 2 +-
 scheduler/dirsvc.c   | 6 ++++++
 scheduler/printers.c | 4 +++-
 5 files changed, 16 insertions(+), 2 deletions(-)

diff --git a/scheduler/conf.c b/scheduler/conf.c
index 9c1be7089..52f2a6d35 100644
--- scheduler/conf.c.orig
+++ scheduler/conf.c
@@ -745,7 +745,7 @@ cupsdReadConfiguration(void)
   DefaultShared            = CUPS_DEFAULT_DEFAULT_SHARED;
 
 #if defined(HAVE_DNSSD) || defined(HAVE_AVAHI)
-  cupsdSetString(&DNSSDSubTypes, "_cups,_print");
+  cupsdSetString(&DNSSDSubTypes, "_cups,_print,_universal");
   cupsdClearString(&DNSSDHostName);
 #endif /* HAVE_DNSSD || HAVE_AVAHI */
 
