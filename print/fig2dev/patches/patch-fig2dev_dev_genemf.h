$NetBSD: patch-fig2dev_dev_genemf.h,v 1.1 2021/04/11 08:09:12 nros Exp $

* remove non-portable header <endian.h>
  fixes build on macosx
  from upstream:
https://sourceforge.net/p/mcj/fig2dev/ci/3897c8034f2eecfa99c645f2b8efa400505a9e27/

--- fig2dev/dev/genemf.h.orig	2021-04-11 07:44:30.139844868 +0000
+++ fig2dev/dev/genemf.h
@@ -30,7 +30,6 @@
 #include "config.h"
 #endif
 
-#include <endian.h>
 
 typedef unsigned char  uchar;
 typedef unsigned short TCHAR;
