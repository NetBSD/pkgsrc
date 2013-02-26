$NetBSD: patch-encfs_OpaqueValue.h,v 1.1 2013/02/26 10:27:37 joerg Exp $

--- encfs/OpaqueValue.h.orig	2013-02-25 17:46:44.000000000 +0000
+++ encfs/OpaqueValue.h
@@ -19,6 +19,8 @@
 #ifndef _OpaqueValue_incl_
 #define _OpaqueValue_incl_
 
+#include <typeinfo>
+
 namespace rel
 {
     class OpaqueValue;
