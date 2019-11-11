$NetBSD: patch-src_Value.cc,v 1.1 2019/11/11 22:03:01 maya Exp $

Fix C++11 compatibility

--- src/Value.cc.orig	2014-12-19 21:24:38.000000000 +0000
+++ src/Value.cc
@@ -146,10 +146,10 @@ namespace enigma {
                 val.str[0] = 0;
                 break;
             case BOOL :
-                val.dval[0] = false;
+                val.dval[0] = 0;
                 break;
             case OBJECT :
-                val.dval[0] = (double) NULL;
+                val.dval[0] = 0;
                 break;
             case NAMEDOBJECT:
                 ASSERT(false, XLevelRuntime, "Value: illegal type usage");
