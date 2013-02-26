$NetBSD: patch-sysdeps_solaris_glibtop__server.h,v 1.1 2013/02/26 15:54:16 jperkin Exp $

Add missing defines.

--- sysdeps/solaris/glibtop_server.h.orig	2011-06-01 15:40:47.000000000 +0000
+++ sysdeps/solaris/glibtop_server.h
@@ -45,6 +45,8 @@ G_BEGIN_DECLS
 #define GLIBTOP_SUID_NETLOAD		0
 #define GLIBTOP_SUID_NETLIST		0
 #define GLIBTOP_SUID_PPP		0
+#define GLIBTOP_SUID_PROC_WD		0
+#define GLIBTOP_SUID_PROC_AFFINITY	0
 
 G_END_DECLS
 
