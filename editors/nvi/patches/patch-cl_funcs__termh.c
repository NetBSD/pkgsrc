$NetBSD: patch-cl_funcs__termh.c,v 1.1 2017/04/04 07:53:23 fhajny Exp $

-  Suppress compile time warning on Linux and prevent segfault on Darwin when
 run as nex.
-  Original patch was found in release 13 of nvi 1.81.6 for debian under the
 name 19include_term_h.patch.

##From: <hesso@pool.math.tu-berlin.de>
##Subject: Add <term.h> to the include list to suppress a few warnings.

--- cl/cl_funcs.c.orig	2007-11-18 17:41:42.000000000 +0100
+++ cl/cl_funcs.c	2008-05-01 18:23:08.000000000 +0200
@@ -18,6 +18,7 @@
 #include <sys/time.h>
 
 #include <bitstring.h>
+#include <term.h>
 #include <ctype.h>
 #include <signal.h>
 #include <stdio.h>
