$NetBSD: patch-dnsdist.cc,v 1.7 2023/08/22 20:31:36 adam Exp $

Always use the pkgsrc editline layout.

--- dnsdist.cc.orig	2023-03-28 11:06:46.000000000 +0000
+++ dnsdist.cc
@@ -33,7 +33,7 @@
 #include <unistd.h>
 
 #ifdef HAVE_LIBEDIT
-#if defined (__OpenBSD__) || defined(__NetBSD__)
+#if 1
 // If this is not undeffed, __attribute__ wil be redefined by /usr/include/readline/rlstdc.h
 #undef __STRICT_ANSI__
 #include <readline/readline.h>
