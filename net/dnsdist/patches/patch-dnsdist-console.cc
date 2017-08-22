$NetBSD: patch-dnsdist-console.cc,v 1.2 2017/08/22 17:00:35 fhajny Exp $

Add NetBSD support.

--- dnsdist-console.cc.orig	2017-08-21 12:52:09.000000000 +0000
+++ dnsdist-console.cc
@@ -23,7 +23,7 @@
 #include "sodcrypto.hh"
 #include "pwd.h"
 
-#if defined (__OpenBSD__)
+#if defined (__OpenBSD__) || defined (__NetBSD__)
 #include <readline/readline.h>
 #include <readline/history.h>
 #else
