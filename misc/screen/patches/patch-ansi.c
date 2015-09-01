$NetBSD: patch-ansi.c,v 1.1 2015/09/01 13:34:47 kim Exp $

Fix for bug 45713, adapted from this master branch commit:
http://git.savannah.gnu.org/cgit/screen.git/patch/?id=c336a32a1dcd445e6b83827f83531d4c6414e2cd

From c336a32a1dcd445e6b83827f83531d4c6414e2cd Mon Sep 17 00:00:00 2001
From: Kuang-che Wu <kcwu@csie.org>
Date: Mon, 31 Aug 2015 17:49:57 +0000
Subject: Fix stack overflow due to too deep recursion

Bug: 45713

How to reproduce:
Run this command inside screen
$ printf '\x1b[10000000T'

screen will recursively call MScrollV to depth n/256.
This is time consuming and will overflow stack if n is huge.

--- ansi.c.orig	2015-06-28 21:22:55.000000000 +0000
+++ ansi.c	2015-09-01 13:02:33.000000000 +0000
@@ -2502,13 +2502,13 @@
     return;
   if (n > 0)
     {
+      if (ye - ys + 1 < n)
+	n = ye - ys + 1;
       if (n > 256)
 	{
 	  MScrollV(p, n - 256, ys, ye, bce);
 	  n = 256;
 	}
-      if (ye - ys + 1 < n)
-	n = ye - ys + 1;
 #ifdef COPY_PASTE
       if (compacthist)
 	{
@@ -2562,14 +2562,14 @@
     }
   else
     {
-      if (n < -256)
-	{
-	  MScrollV(p, n + 256, ys, ye, bce);
-	  n = -256;
-	}
       n = -n;
       if (ye - ys + 1 < n)
 	n = ye - ys + 1;
+      if (n > 256)
+	{
+	  MScrollV(p, - (n - 256), ys, ye, bce);
+	  n = 256;
+	}
 
       ml = p->w_mlines + ye;
       /* Clear lines */
