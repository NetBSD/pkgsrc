$NetBSD: patch-src_palfilt.c,v 1.1 2026/02/13 15:09:13 nia Exp $

Not sure what their intention was, but fmul doesn't exist...

From cdf4b8d7162edfa195da1b5fc040fdb9f289961c Mon Sep 17 00:00:00 2001
From: Richard Cook <rcook@rcook.org>
Date: Sun, 31 May 2015 14:50:01 -0700
Subject: [PATCH] Fix upper bound of coefficient arrays

--- src/palfilt.c.orig	2026-02-13 13:35:14.838506802 +0000
+++ src/palfilt.c
@@ -3,8 +3,12 @@
 #include <allegro.h>
 #include "elk.h"
 
-fixed ACoef[2],ACoef2[2];
-fixed BCoef[2],BCoef2[2];
+#ifndef fmul
+#define fmul(x,y) (x*y)
+#endif
+
+fixed ACoef[2],ACoef2[3];
+fixed BCoef[2],BCoef2[3];
 
 void initcoef()
 {
