$NetBSD: patch-dnsdist-console.cc,v 1.4 2020/04/23 07:43:30 jperkin Exp $

Always use the pkgsrc editline layout.

--- dnsdist-console.cc.orig	2018-11-08 10:15:21.000000000 +0000
+++ dnsdist-console.cc
@@ -24,7 +24,7 @@
 #include <pwd.h>
 #include <thread>
 
-#if defined (__OpenBSD__) || defined(__NetBSD__)
+#if 1
 #include <readline/readline.h>
 #include <readline/history.h>
 #else
