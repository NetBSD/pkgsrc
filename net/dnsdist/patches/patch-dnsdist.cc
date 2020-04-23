$NetBSD: patch-dnsdist.cc,v 1.5 2020/04/23 07:43:30 jperkin Exp $

Always use the pkgsrc editline layout.

--- dnsdist.cc.orig	2018-11-08 10:15:21.000000000 +0000
+++ dnsdist.cc
@@ -31,7 +31,7 @@
 #include <sys/resource.h>
 #include <unistd.h>
 
-#if defined (__OpenBSD__) || defined(__NetBSD__)
+#if 1
 #include <readline/readline.h>
 #else
 #include <editline/readline.h>
