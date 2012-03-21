$NetBSD: patch-src_topology.c,v 1.1.1.1 2012/03/21 13:31:35 asau Exp $

--- src/topology.c.orig	2012-01-22 08:06:22.000000000 +0000
+++ src/topology.c
@@ -2168,6 +2168,11 @@ hwloc_discover(struct hwloc_topology *to
     hwloc_look_darwin(topology);
 #    endif /* HWLOC_DARWIN_SYS */
 
+#    ifdef HWLOC_NETBSD_SYS
+#      define HAVE_OS_SUPPORT
+    hwloc_look_netbsd(topology);
+#    endif /* HWLOC_NETBSD_SYS */
+
 #    ifdef HWLOC_FREEBSD_SYS
 #      define HAVE_OS_SUPPORT
     hwloc_look_freebsd(topology);
