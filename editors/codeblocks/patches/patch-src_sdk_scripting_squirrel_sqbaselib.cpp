$NetBSD: patch-src_sdk_scripting_squirrel_sqbaselib.cpp,v 1.1 2020/05/22 01:18:14 joerg Exp $

--- src/sdk/scripting/squirrel/sqbaselib.cpp.orig	2020-05-21 21:08:45.893283969 +0000
+++ src/sdk/scripting/squirrel/sqbaselib.cpp
@@ -1,6 +1,9 @@
 /*
 	see copyright notice in squirrel.h
 */
+#include <stdlib.h>
+#include <stdarg.h>
+#include <ctype.h>
 #include "sqpcheader.h"
 #include "sqvm.h"
 #include "sqstring.h"
@@ -9,9 +12,6 @@
 #include "sqfuncproto.h"
 #include "sqclosure.h"
 #include "sqclass.h"
-#include <stdlib.h>
-#include <stdarg.h>
-#include <ctype.h>
 
 bool str2num(const SQChar *s,SQObjectPtr &res)
 {
