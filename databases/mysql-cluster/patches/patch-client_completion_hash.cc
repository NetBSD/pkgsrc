$NetBSD: patch-client_completion_hash.cc,v 1.1.1.1 2014/12/01 05:58:03 jnemeth Exp $

* Portability: include <bstring.h> if exists.

--- client/completion_hash.cc.orig	2010-02-04 11:36:51.000000000 +0000
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
 
