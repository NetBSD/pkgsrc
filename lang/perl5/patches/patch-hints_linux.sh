$NetBSD: patch-hints_linux.sh,v 1.1 2019/04/23 09:27:46 adam Exp $

We intentionally wire down the 'libswanted' list in the package Makefile,
so don't let the hints file add new libraries that may be found outside
Pkgsrc control.

--- hints/linux.sh.orig	2014-05-26 13:34:20.000000000 +0000
+++ hints/linux.sh
@@ -61,10 +61,6 @@
 
 # Debian 4.0 puts ndbm in the -lgdbm_compat library.
 echo $libs
-if echo " $libswanted " | grep -q ' gdbm '; then
-    # Only add if gdbm is in libswanted.
-    libswanted="$libswanted gdbm_compat"
-fi
 
 # Configure may fail to find lstat() since it's a static/inline
 # function in <sys/stat.h>.
