$NetBSD: patch-cl_screen__termh.c,v 1.1 2017/04/04 07:53:23 fhajny Exp $

-  Suppress compile time warning on Linux and prevent segfault on Darwin when
 run as nex.
-  Original patch was found in release 13 of nvi 1.81.6 for debian under the
 name 19include_term_h.patch. 

##From: <hesso@pool.math.tu-berlin.de>
##Subject: Add <term.h> to the include list to suppress a few warnings.

--- cl/cl_screen.c.orig	2007-11-18 17:41:42.000000000 +0100
+++ cl/cl_screen.c	2008-05-01 18:23:02.000000000 +0200
@@ -17,6 +17,7 @@
 #include <sys/queue.h>
 
 #include <bitstring.h>
+#include <term.h>
 #include <errno.h>
 #include <signal.h>
 #include <stdio.h>
