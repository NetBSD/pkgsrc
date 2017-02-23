$NetBSD: patch-lib_util_nstring.h,v 1.1 2017/02/23 23:13:43 wiz Exp $

Add missing header for strcasecmp and strncasecmp.

--- lib/util/nstring.h.orig	2015-01-23 11:43:58.000000000 +0000
+++ lib/util/nstring.h
@@ -3,6 +3,7 @@
 
 #include <stdarg.h>
 #include <string.h>
+#include <strings.h>
 #include <ctype.h>
 
 #include "pm_c_util.h"
