$NetBSD: patch-3rdParty_StormLib_src_StormPort.h,v 1.1 2019/10/16 12:00:51 nia Exp $

strings.h for strncasecmp.

--- 3rdParty/StormLib/src/StormPort.h.orig	2019-10-09 22:34:02.000000000 +0000
+++ 3rdParty/StormLib/src/StormPort.h
@@ -162,6 +162,7 @@
   #include <stdio.h>
   #include <stdarg.h>
   #include <string.h>
+  #include <strings.h>
   #include <ctype.h>
   #include <assert.h>
   #include <errno.h>
