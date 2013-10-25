$NetBSD: patch-Makefile.inc,v 1.1 2013/10/25 04:09:14 dholland Exp $

Allow setting -m32 or not from the pkgsrc makefile.

--- Makefile.inc~	2010-07-09 12:40:18.000000000 +0000
+++ Makefile.inc
@@ -1,8 +1,7 @@
 ### Configurable variables:
 
 OPT = -O3
-#ARCH = -m32
-ARCH = 
+ARCH = ${PKGSRC_M32}
 
 # CC, STRIP = actually sourced from LIBDIR/MACHINE/config
 INSTALL = cp
