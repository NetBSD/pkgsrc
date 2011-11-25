$NetBSD: patch-src_coolkey_object.cpp,v 1.1 2011/11/25 22:17:49 joerg Exp $

--- src/coolkey/object.cpp.orig	2011-11-25 17:09:14.000000000 +0000
+++ src/coolkey/object.cpp
@@ -21,6 +21,7 @@
 #include "PKCS11Exception.h"
 #include "object.h"
 #include <algorithm>
+#include <cstring>
 
 using std::find_if;
 
