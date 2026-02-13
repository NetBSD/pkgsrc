$NetBSD: patch-src_config.c,v 1.1 2026/02/13 15:09:13 nia Exp $

From f938c5828f88de9bc87601a7108452c763d20887 Mon Sep 17 00:00:00 2001
From: Richard Cook <rcook@rcook.org>
Date: Sun, 31 May 2015 14:37:27 -0700
Subject: [PATCH] Fix variable signedness

--- src/config.c.orig	2026-02-13 13:47:19.569907832 +0000
+++ src/config.c
@@ -6,7 +6,7 @@
 #include "elk.h"
 
 FILE *cfgfile;
-uint8_t cfgbuffer[1024];
+char cfgbuffer[1024];
 int sndex;
 int sndint;
 int firstbyte;
@@ -84,6 +84,11 @@ void loadconfig()
         char fn[256];
         sprintf(fn,"%s/elk.cfg",exedir);
         cfgfile=fopen(fn,"rt");
+        if (!cfgfile)
+        {
+                fprintf(stderr, "elkulator: Config file %s does not exist\n", fn);
+                exit(1);
+        }
         tapespeed=getintcfg("tapespeed",0);
         plus1=getintcfg("plus1",0);
         plus3=getintcfg("plus3",0);
