$NetBSD: patch-airprint-scheduler_printers.c,v 1.3 2020/01/29 22:56:50 prlw1 Exp $

From debian:
From 7147c814439aafb26ff0262a7d6b8ef56d20969f Mon Sep 17 00:00:00 2001
From: Till Kamppeter <till.kamppeter@gmail.com>
Date: Tue, 9 Aug 2016 18:11:04 +0200
Subject: For PWG Raster, add required IPP attributes

Add required by IPP Everywhere for PWG Raster when PWG Raster as input format
is supported

Bug-Upstream: https://www.cups.org/str.php?L4428
Last-Update: 2015-02-10
Patch-Name: pwg-raster-attributes.patch

First two hunks of that patch are no longer needed:
https://github.com/apple/cups/issues/5641
---
 scheduler/printers.c | 77 +++++++++++++++++++++++++++++++++++++++++++-
 1 file changed, 76 insertions(+), 1 deletion(-)

diff --git a/scheduler/printers.c b/scheduler/printers.c
index bb99907ad..a0ebcbd3e 100644
--- scheduler/printers.c.orig	2019-11-17 12:21:47.966025953 +0000
+++ scheduler/printers.c
@@ -3731,7 +3806,9 @@ add_printer_formats(cupsd_printer_t *p)	
       }
       else if (!_cups_strcasecmp(type->super, "image"))
       {
-        if (!_cups_strcasecmp(type->type, "jpeg"))
+        if (!_cups_strcasecmp(type->type, "urf"))
+	  strlcat(pdl, "image/urf,", sizeof(pdl));
+	else if (!_cups_strcasecmp(type->type, "jpeg"))
 	  strlcat(pdl, "image/jpeg,", sizeof(pdl));
 	else if (!_cups_strcasecmp(type->type, "png"))
 	  strlcat(pdl, "image/png,", sizeof(pdl));
