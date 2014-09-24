$NetBSD: patch-src_osd_osdcore.h,v 1.2 2014/09/24 12:33:44 jperkin Exp $

Include stdarg.h for va_list.

--- src/osd/osdcore.h.orig	2014-04-25 09:31:28.000000000 +0000
+++ src/osd/osdcore.h
@@ -19,6 +19,7 @@
 #ifndef __OSDCORE_H__
 #define __OSDCORE_H__
 
+#include <stdarg.h>
 #include "osdcomm.h"
 #include "delegate.h"
 
