$NetBSD: patch-dnsdist-console.cc,v 1.1 2017/03/31 20:49:51 fhajny Exp $

Add NetBSD support.

--- dnsdist-console.cc.orig	2016-12-29 12:45:46.000000000 +0000
+++ dnsdist-console.cc
@@ -22,7 +22,7 @@
 #include "dnsdist.hh"
 #include "sodcrypto.hh"
 
-#if defined (__OpenBSD__)
+#if defined (__OpenBSD__) || defined (__NetBSD__)
 #include <readline/readline.h>
 #include <readline/history.h>
 #else
