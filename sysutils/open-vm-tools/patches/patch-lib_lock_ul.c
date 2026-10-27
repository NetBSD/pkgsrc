$NetBSD: patch-lib_lock_ul.c,v 1.1 2026/10/27 20:33:09 wiz Exp $

Match function prototype.

--- lib/lock/ul.c.orig	2026-10-27 20:29:48.978847772 +0000
+++ lib/lock/ul.c
@@ -29,7 +29,7 @@ static Bool mxUserCollectLockingTree = FALSE;
 static Bool mxInPanic = FALSE;  // track when involved in a panic
 static Bool mxUserCollectLockingTree = FALSE;
 
-Bool (*MXUserTryAcquireForceFail)() = NULL;
+Bool (*MXUserTryAcquireForceFail)(const char *name) = NULL;
 
 static MX_Rank (*MXUserMxCheckRank)(void) = NULL;
 static void (*MXUserMxLockLister)(void) = NULL;
