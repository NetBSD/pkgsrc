$NetBSD: patch-src_coolkey_log.cpp,v 1.1 2011/11/25 22:17:49 joerg Exp $

--- src/coolkey/log.cpp.orig	2011-11-25 17:05:01.000000000 +0000
+++ src/coolkey/log.cpp
@@ -21,6 +21,8 @@
 #include "mypkcs11.h"
 #include <assert.h>
 #include <stdio.h>
+#include <stdlib.h>
+#include <strings.h>
 #include "log.h"
 #include <cstdarg>
 #include "PKCS11Exception.h"
