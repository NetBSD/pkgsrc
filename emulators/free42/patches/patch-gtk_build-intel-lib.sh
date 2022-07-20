$NetBSD: patch-gtk_build-intel-lib.sh,v 1.3 2022/07/20 05:03:06 dbj Exp $

Avoid pkgsrc libtool on Darwin.

Include fenv.h explicitly on QNX/Darwin/Apple/FreeBSD/NetBSD

On NetBSD, build intel lib as if it was FreeBSD

--- gtk/build-intel-lib.sh.orig	2022-06-16 09:39:50.000000000 +0000
+++ gtk/build-intel-lib.sh
@@ -45,6 +45,26 @@ tar xvfz ../inteldecimal/IntelRDFPMathLi
 cd IntelRDFPMathLib20U1
 patch -p0 <../intel-lib-linux.patch
 
+# avoid pkgsrc libtool on Darwin
+mv LIBRARY/makefile.iml_head LIBRARY/makefile.iml_head.orig && \
+    sed -e 's/libtool/xcrun libtool/' \
+        LIBRARY/makefile.iml_head.orig > LIBRARY/makefile.iml_head
+
+# Fixup fenv.h inclusion detection. NetBSD uses _FENV_H_, Darwin uses __FENV_H__
+# also actually include fenv.h on platforms that use it.
+mv LIBRARY/src/bid_functions.h LIBRARY/src/bid_functions.h.orig && \
+    sed -e 's/!defined (_FENV_H)/& \&\& !defined(_FENV_H_) \&\& !defined(__FENV_H__)/' \
+        -e 's/^#ifdef __QNX__/#if defined(__QNX__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)/' \
+        LIBRARY/src/bid_functions.h.orig > LIBRARY/src/bid_functions.h
+
+# make NetBSD look like FreeBSD to the Makefiles, this is a little hackish
+if [ `uname -s` = "NetBSD" ]; then
+  OS_ARG="CFLAGS_OPT=-DLINUX"
+  mv LIBRARY/makefile.iml_head LIBRARY/makefile.iml_head.orig2 && \
+      sed -e 's/FreeBSD/NetBSD/' -e 's/FREEBSD/NETBSD/' \
+          LIBRARY/makefile.iml_head.orig2 > LIBRARY/makefile.iml_head
+fi
+
 # When building for architectures other than x86 or x86_64, I remove the
 # section titled "Determine host architecture" in
 # IntelRDFPMathLib20U1/LIBRARY/makefile.iml_head, and replace it with a simple
