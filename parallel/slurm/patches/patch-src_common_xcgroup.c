$NetBSD: patch-src_common_xcgroup.c,v 1.1 2013/12/06 06:05:30 asau Exp $

--- src/common/xcgroup.c.orig	2013-11-04 21:19:15.000000000 +0000
+++ src/common/xcgroup.c
@@ -217,7 +217,7 @@ int xcgroup_ns_mount(xcgroup_ns_t* cgns)
 		options = opt_combined;
 	}
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__APPLE__)
 	if (mount("cgroup", cgns->mnt_point,
 		  MS_NOSUID|MS_NOEXEC|MS_NODEV, options))
 #else
