$NetBSD: patch-filter_raster.c,v 1.1 2014/06/17 13:17:13 wiz Exp $

* OpenBSD needs stdint.h

--- filter/raster.c.orig	2011-09-20 18:36:33.000000000 +0000
+++ filter/raster.c
@@ -50,6 +50,7 @@
 #  include <io.h>
 #  include <winsock2.h>			/* for htonl() definition */
 #else
+#  include <stdint.h>
 #  include <unistd.h>
 #endif /* WIN32 || __EMX__ */
 
