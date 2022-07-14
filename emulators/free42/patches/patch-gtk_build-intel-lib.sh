$NetBSD: patch-gtk_build-intel-lib.sh,v 1.1 2022/07/14 05:09:46 dbj Exp $

Avoid pkgsrc libtool on Darwin.

On NetBSD, build intel lib as if it was FreeBSD

--- gtk/build-intel-lib.sh.orig	2022-06-16 09:39:50.000000000 +0000
+++ gtk/build-intel-lib.sh
@@ -45,6 +45,19 @@ tar xvfz ../inteldecimal/IntelRDFPMathLi
 cd IntelRDFPMathLib20U1
 patch -p0 <../intel-lib-linux.patch
 
+# avoid pkgsrc libtool on Darwin
+mv LIBRARY/makefile.iml_head LIBRARY/makefile.iml_head.orig && \
+    sed -e 's/libtool/xcrun libtool/' \
+        LIBRARY/makefile.iml_head.orig > LIBRARY/makefile.iml_head
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
