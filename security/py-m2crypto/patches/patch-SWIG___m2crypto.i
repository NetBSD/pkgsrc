$NetBSD: patch-SWIG___m2crypto.i,v 1.1 2020/09/17 08:56:38 jperkin Exp $

Find local includes correctly.

--- SWIG/_m2crypto.i.orig	2020-01-30 08:17:01.000000000 +0000
+++ SWIG/_m2crypto.i
@@ -46,9 +46,9 @@ typedef unsigned __int64 uint64_t;
 
 #include <openssl/err.h>
 #include <openssl/rand.h>
-#include <_lib.h>
-#include <libcrypto-compat.h>
-#include <py3k_compat.h>
+#include "_lib.h"
+#include "libcrypto-compat.h"
+#include "py3k_compat.h"
 
 #include "compile.h"
 
