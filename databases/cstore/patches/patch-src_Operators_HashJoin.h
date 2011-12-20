$NetBSD: patch-src_Operators_HashJoin.h,v 1.1 2011/12/20 13:42:47 wiz Exp $

Add missing header.

--- src/Operators/HashJoin.h.orig	2006-09-29 18:20:44.000000000 +0000
+++ src/Operators/HashJoin.h
@@ -44,7 +44,7 @@
 #include "../Wrappers/MultiBlock.h"
 #include "../Util/HashMap.h"
 #include <math.h>
-#include <hash_map.h>
+#include <hash_map>
 
 class PBObject {
  public:
