$NetBSD: patch-usrp_host_swig_usrp_prims.i,v 1.1 2012/03/10 21:47:30 markd Exp $

--- usrp/host/swig/usrp_prims.i.orig	2010-06-01 05:04:09.000000000 +0000
+++ usrp/host/swig/usrp_prims.i
@@ -32,6 +32,10 @@
  * Linux, *BSD and Mac OS/X.  http://libusb.sourceforge.net
  */
 
+%{
+#include <stddef.h>
+%}
+
 %include <stl.i>	// pick up string stuff
 
 
