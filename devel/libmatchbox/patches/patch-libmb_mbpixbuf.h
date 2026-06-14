$NetBSD: patch-libmb_mbpixbuf.h,v 1.1 2026/06/14 19:11:54 nia Exp $

Include appropriate header to avoid implicit function declaration
of mb_want_warnings().

--- libmb/mbpixbuf.h.orig	2026-06-14 19:05:10.245826774 +0000
+++ libmb/mbpixbuf.h
@@ -21,6 +21,7 @@
  */
 
 #include "libmb/mbconfig.h"
+#include "libmb/mbutil.h"
 
 #include <stdio.h>
 #include <stdlib.h>
