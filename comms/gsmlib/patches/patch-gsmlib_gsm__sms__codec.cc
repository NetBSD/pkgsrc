$NetBSD: patch-gsmlib_gsm__sms__codec.cc,v 1.1 2011/11/24 14:17:06 joerg Exp $

--- gsmlib/gsm_sms_codec.cc.orig	2011-11-23 15:41:35.000000000 +0000
+++ gsmlib/gsm_sms_codec.cc
@@ -20,6 +20,7 @@
 #include <time.h>
 #include <strstream>
 #include <iomanip>
+#include <limits.h>
 #ifdef HAVE_STRING_H
 #include <string.h>
 #endif
