$NetBSD: patch-src-malloc-gmalloc.c,v 1.1 2026/01/03 03:26:07 dholland Exp $

Use the right grade of baling wire to match the chewing gum flavor.
Fixes the build with gcc14.

--- src/malloc/gmalloc.c~	2008-06-02 13:54:05.000000000 +0000
+++ src/malloc/gmalloc.c
@@ -5,6 +5,8 @@
 #define USE_PTHREAD
 #endif
 
+#define HAVE_CONFIG_H
+
 /* The malloc headers and source files from the C library follow here.  */
 
 /* Declarations for `malloc' and friends.
