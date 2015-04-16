$NetBSD: patch-client_completion_hash.cc,v 1.1 2015/04/16 20:20:15 ryoon Exp $

Portability: include <bstring.h> if exists.

--- client/completion_hash.cc.orig	2015-02-13 12:07:00.000000000 +0000
+++ client/completion_hash.cc
@@ -22,6 +22,10 @@
 
 #include <my_global.h>
 #include <m_string.h>
+#ifdef NEEDS_BSTRING_H                         // defines bzero()
+#include <bstring.h>
+#endif
+
 #include <my_sys.h>
 #include "completion_hash.h"
 
