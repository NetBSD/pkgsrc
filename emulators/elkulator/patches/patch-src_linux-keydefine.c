$NetBSD: patch-src_linux-keydefine.c,v 1.1 2026/02/13 15:09:13 nia Exp $

From 5758c64c9c058aa196254eb85d090eef246c551a Mon Sep 17 00:00:00 2001
From: Richard Cook <rcook@rcook.org>
Date: Sat, 30 May 2015 00:19:37 -0700
Subject: [PATCH] Use format strings with printf-style functions

--- src/linux-keydefine.c.orig	2026-02-13 13:35:14.836793916 +0000
+++ src/linux-keydefine.c
@@ -77,7 +77,7 @@ int d_getkey(int msg, DIALOG *d, int cd)
                         }
                 }
 
-                textprintf_ex(screen,font,x+8,y+40,makecol(255,255,255),0,s);
+                textprintf_ex(screen, font, x + 8, y + 40, makecol(255, 255, 255), 0, "%s", s);
                 
                 textprintf_ex(screen,font,x+8,y+56,makecol(255,255,255),0,"Please press new key...");
 getnewkey:
