$NetBSD: patch-configure.sh,v 1.1 2015/09/14 14:00:01 manu Exp $

NetBSD extended attribute support, from upstream

--- configure.sh.orig	2015-09-03 03:42:33.000000000 +0200
+++ configure.sh	2015-09-03 03:44:27.000000000 +0200
@@ -8867,9 +8867,9 @@
     { $as_echo "$as_me:${as_lineno-$LINENO}: result: no" >&5
 $as_echo "no" >&6; }
 else
     case "$host_os" in
-    *linux*)
+    *linux*|*netbsd*)
 	{ $as_echo "$as_me:${as_lineno-$LINENO}: result: Using Linux xattrs" >&5
 $as_echo "Using Linux xattrs" >&6; }
 
 $as_echo "#define HAVE_LINUX_XATTRS 1" >>confdefs.h
