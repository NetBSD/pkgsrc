$NetBSD: patch-src_target.cpp,v 1.1 2019/02/17 12:33:40 maya Exp $

--- src/target.cpp.orig	2019-02-17 10:28:53.000000000 +0000
+++ src/target.cpp
@@ -743,6 +743,7 @@ uint32_t target_c_type_size_in_bits(cons
         case OsMacOSX:
         case OsZen:
         case OsFreeBSD:
+	case OsNetBSD:
         case OsOpenBSD:
             switch (id) {
                 case CIntTypeShort:
@@ -783,7 +784,6 @@ uint32_t target_c_type_size_in_bits(cons
         case OsIOS:
         case OsKFreeBSD:
         case OsLv2:
-        case OsNetBSD:
         case OsSolaris:
         case OsHaiku:
         case OsMinix:
