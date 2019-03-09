$NetBSD: patch-apps_gdalserver.cpp,v 1.1 2019/03/09 01:54:59 gdt Exp $

Define _NETBSD_SOURCE on NetBSD to work around a mysterious problem
with <string>, where apparently too much is hidden because of the
XOPEN request.  Probably this is not adequate, but I am choosing to
narrowly fix the case I can debug.

\todo File upstream.

--- apps/gdalserver.cpp.orig	2018-12-14 15:40:20.000000000 +0000
+++ apps/gdalserver.cpp
@@ -29,6 +29,14 @@
 // So that __USE_XOPEN2K is defined to have getaddrinfo
 #ifndef __sun__
 #define _XOPEN_SOURCE 600
+#ifdef __NetBSD__
+/*
+ * Defining _XOPEN_SOURCE causes other interfaces to be hidden.  Something goes
+ * wrong with /usr/include/g++/string.
+ * \todo Address upstream.
+ */
+#define _NETBSD_SOURCE 1
+#endif
 #endif
 
 #include "cpl_port.h"
