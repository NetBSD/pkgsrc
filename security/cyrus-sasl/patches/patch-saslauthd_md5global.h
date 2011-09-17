$NetBSD: patch-saslauthd_md5global.h,v 1.1 2011/09/17 11:32:02 obache Exp $

* use standard types for certain bits types.

--- saslauthd/md5global.h.orig	2003-03-28 19:59:24.000000000 +0000
+++ saslauthd/md5global.h
@@ -3,6 +3,13 @@
 #ifndef MD5GLOBAL_H
 #define MD5GLOBAL_H
 
+#ifdef HAVE_STDINT_H
+#include <stdint.h>
+#endif
+#ifdef HAVE_INTTYPES_H
+#include <inttypes.h>
+#endif
+
 /* PROTOTYPES should be set to one if and only if the compiler supports
   function argument prototyping.
 The following makes PROTOTYPES default to 0 if it has not already
@@ -15,13 +22,13 @@ The following makes PROTOTYPES default t
 /* POINTER defines a generic pointer type */
 typedef unsigned char *POINTER;
 
-typedef signed char INT1;		/*  8 bits */
-typedef short INT2;			/* 16 bits */
-typedef int INT4;			/* 32 bits */
+typedef int8_t INT1;		/*  8 bits */
+typedef int16_t INT2;		/* 16 bits */
+typedef int32_t INT4;		/* 32 bits */
 /* There is no 64 bit type */
-typedef unsigned char UINT1;		/*  8 bits */
-typedef unsigned short UINT2;		/* 16 bits */
-typedef unsigned int UINT4;		/* 32 bits */
+typedef uint8_t UINT1;		/*  8 bits */
+typedef uint16_t UINT2;		/* 16 bits */
+typedef uint32_t UINT4;		/* 32 bits */
 /* There is no 64 bit type */
 
 /* PROTO_LIST is defined depending on how PROTOTYPES is defined above.
