$NetBSD: patch-libinetutils_setsig.c,v 1.1 2026/09/26 07:02:59 wiz Exp $

From f756321da9b964fc27fc43652b73913117883047 Mon Sep 17 00:00:00 2001
From: Brian Mak <brian.mak@hpe.com>
Date: Mon, 14 Sep 2026 15:44:23 -0700
Subject: [PATCH] libinetutils: zero-initialize sigactions and sigvecs

This commit fixes CVE-2026-95510.

* libinetutils/setsig.c (setsig): Initialize the siactions and sigvecs
to zero.
Copyright-paperwork-exempt: Yes
---
 libinetutils/setsig.c | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)

--- libinetutils/setsig.c.orig	2026-04-29 07:53:25.000000000 +0000
+++ libinetutils/setsig.c
@@ -30,7 +30,7 @@ setsig (int sig, sighandler_t handler)
 setsig (int sig, sighandler_t handler)
 {
 #ifdef HAVE_SIGACTION
-  struct sigaction sa, osa;
+  struct sigaction sa = { 0 }, osa = { 0 };
   sigemptyset (&sa.sa_mask);
   sigemptyset (&osa.sa_mask);
 # ifdef SA_RESTART
@@ -42,7 +42,7 @@ setsig (int sig, sighandler_t handler)
   return osa.sa_handler;
 #else /* !HAVE_SIGACTION */
 # ifdef HAVE_SIGVEC
-  struct sigvec sv, osv;
+  struct sigvec sv = { 0 }, osv = { 0 };
   sigemptyset (&sv.sv_mask);
   sigemptyset (&osv.sv_mask);
   sv.sv_handler = handler;
