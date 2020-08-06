$NetBSD: patch-dnsdist.cc,v 1.6 2020/08/06 16:28:03 adam Exp $

Always use the pkgsrc editline layout.

--- dnsdist.cc.orig	2020-07-29 16:09:33.000000000 +0000
+++ dnsdist.cc
@@ -31,7 +31,7 @@
 #include <sys/resource.h>
 #include <unistd.h>
 
-#if defined (__OpenBSD__) || defined(__NetBSD__)
+#if 1
 // If this is not undeffed, __attribute__ wil be redefined by /usr/include/readline/rlstdc.h
 #undef __STRICT_ANSI__
 #include <readline/readline.h>
