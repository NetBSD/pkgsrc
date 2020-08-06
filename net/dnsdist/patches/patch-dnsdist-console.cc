$NetBSD: patch-dnsdist-console.cc,v 1.5 2020/08/06 16:28:03 adam Exp $

Always use the pkgsrc editline layout.

--- dnsdist-console.cc.orig	2020-07-28 07:39:28.000000000 +0000
+++ dnsdist-console.cc
@@ -24,7 +24,7 @@
 #include <pwd.h>
 #include <thread>
 
-#if defined (__OpenBSD__) || defined(__NetBSD__)
+#if 1
 // If this is not undeffed, __attribute__ wil be redefined by /usr/include/readline/rlstdc.h
 #undef __STRICT_ANSI__
 #include <readline/readline.h>
