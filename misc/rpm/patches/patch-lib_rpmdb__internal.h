$NetBSD: patch-lib_rpmdb__internal.h,v 1.1 2013/09/15 12:32:22 joerg Exp $

--- lib/rpmdb_internal.h.orig	2013-09-14 20:58:16.000000000 +0000
+++ lib/rpmdb_internal.h
@@ -148,7 +148,7 @@ int rpmdbPruneIterator(rpmdbMatchIterato
 RPM_GNUC_INTERNAL
 rpmdbMatchIterator rpmdbNewIterator(rpmdb db, rpmDbiTagVal dbitag);
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
 /**
  *  * Mergesort, same arguments as qsort(2).
  *   */
