$NetBSD: patch-dnsdist.cc,v 1.1 2017/03/31 20:49:51 fhajny Exp $

Add NetBSD support.

--- dnsdist.cc.orig	2016-12-29 12:45:46.000000000 +0000
+++ dnsdist.cc
@@ -27,7 +27,7 @@
 #include <limits>
 #include "dolog.hh"
 
-#if defined (__OpenBSD__)
+#if defined (__OpenBSD__) || defined (__NetBSD__)
 #include <readline/readline.h>
 #else
 #include <editline/readline.h>
