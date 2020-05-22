$NetBSD: patch-src_sdk_scripting_squirrel_sqvm.cpp,v 1.1 2020/05/22 01:18:14 joerg Exp $

--- src/sdk/scripting/squirrel/sqvm.cpp.orig	2020-05-21 21:10:31.622312197 +0000
+++ src/sdk/scripting/squirrel/sqvm.cpp
@@ -1,9 +1,9 @@
 /*
 	see copyright notice in squirrel.h
 */
-#include "sqpcheader.h"
 #include <math.h>
 #include <stdlib.h>
+#include "sqpcheader.h"
 #include "sqopcodes.h"
 #include "sqfuncproto.h"
 #include "sqvm.h"
