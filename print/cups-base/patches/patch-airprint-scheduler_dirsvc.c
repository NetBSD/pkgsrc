$NetBSD: patch-airprint-scheduler_dirsvc.c,v 1.2 2020/05/26 08:36:56 triaxx Exp $

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

diff --git a/scheduler/dirsvc.c b/scheduler/dirsvc.c
index 3dab90ca9..f21942af3 100644
--- scheduler/dirsvc.c.orig
+++ scheduler/dirsvc.c
@@ -440,6 +440,12 @@ dnssdBuildTxtRecord(
     keyvalue[count  ][0] = "pdl";
     keyvalue[count++][1] = p->pdl ? p->pdl : "application/postscript";
 
+    /* iOS 6 does not accept this printer as AirPrint printer if there is
+       no URF txt record or "URF=none", "DM3" is the minimum needed found
+       by try and error */
+    keyvalue[count  ][0] = "URF";
+    keyvalue[count++][1] = "DM3";
+
     if (get_auth_info_required(p, air_str, sizeof(air_str)))
     {
       keyvalue[count  ][0] = "air";
