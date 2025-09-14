$NetBSD: patch-lib_core.c,v 1.1 2025/09/14 16:02:14 wiz Exp $

Add missing header for curl_multi_setopt.

--- lib/core.c.orig	2025-09-14 16:01:16.833016191 +0000
+++ lib/core.c
@@ -19,6 +19,7 @@
  **************************************************************/
 
 #include <errno.h>
+#include <curl/curl.h>
 #include <curl/multi.h>
 
 #include "stringlib.h"
