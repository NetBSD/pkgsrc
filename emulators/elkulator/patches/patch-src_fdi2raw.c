$NetBSD: patch-src_fdi2raw.c,v 1.1 2026/02/13 15:09:13 nia Exp $

From f938c5828f88de9bc87601a7108452c763d20887 Mon Sep 17 00:00:00 2001
From: Richard Cook <rcook@rcook.org>
Date: Sun, 31 May 2015 14:37:27 -0700
Subject: [PATCH] Fix variable signedness

--- src/fdi2raw.c.orig	2026-02-13 13:35:14.835174982 +0000
+++ src/fdi2raw.c
@@ -1945,7 +1945,7 @@ static int decode_lowlevel_track (FDI *f
 	return 1;
 }
 
-static unsigned char fdiid[]={"Formatted Disk Image file"};
+static char fdiid[]={"Formatted Disk Image file"};
 static int bit_rate_table[16] = { 125,150,250,300,500,1000 };
 
 void fdi2raw_header_free (FDI *fdi)
