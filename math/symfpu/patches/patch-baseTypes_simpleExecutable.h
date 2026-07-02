$NetBSD: patch-baseTypes_simpleExecutable.h,v 1.1 2026/07/02 19:34:02 alnsn Exp $

Don't assume that the root directory is named "symfpu".

--- baseTypes/simpleExecutable.h.orig	2026-07-01 22:11:10.431642930 +0000
+++ baseTypes/simpleExecutable.h
@@ -18,9 +18,9 @@
 **
 */
 
-#include "symfpu/utils/properties.h"
-#include "symfpu/core/ite.h"
-#include "symfpu/baseTypes/shared.h"
+#include "utils/properties.h"
+#include "core/ite.h"
+#include "baseTypes/shared.h"
 
 #include <assert.h>
 #include <stdint.h>
