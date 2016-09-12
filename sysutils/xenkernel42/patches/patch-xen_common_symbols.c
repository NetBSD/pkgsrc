$NetBSD: patch-xen_common_symbols.c,v 1.1 2016/09/12 13:22:39 maya Exp $

upstream build fix for GCC5
https://lists.xenproject.org/archives/html/xen-devel/2015-03/msg01687.html

--- xen/common/symbols.c.orig	2014-09-02 06:22:57.000000000 +0000
+++ xen/common/symbols.c
@@ -19,7 +19,7 @@
 #include <xen/spinlock.h>
 
 #ifdef SYMBOLS_ORIGIN
-extern const unsigned int symbols_offsets[1];
+extern const unsigned int symbols_offsets[];
 #define symbols_address(n) (SYMBOLS_ORIGIN + symbols_offsets[n])
 #else
 extern const unsigned long symbols_addresses[];
