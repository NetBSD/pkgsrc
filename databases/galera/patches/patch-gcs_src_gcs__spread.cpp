$NetBSD: patch-gcs_src_gcs__spread.cpp,v 1.1 2023/01/13 16:08:03 wiz Exp $

NetBSD support.
https://github.com/codership/galera/pull/632

--- gcs/src/gcs_spread.cpp.orig	2022-11-02 06:09:14.000000000 +0000
+++ gcs/src/gcs_spread.cpp
@@ -654,7 +654,7 @@ GCS_BACKEND_CREATE_FN(gcs_spread_create)
 	if (spread_priv_name (spread->priv_name,
 #if defined(__sun__)
                               getexecname (),
-#elif defined(__APPLE__) || defined(__FreeBSD__)
+#elif defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
                               getprogname (),
 #elif defined(__linux__)
                               program_invocation_short_name,
