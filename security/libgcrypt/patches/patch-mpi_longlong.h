$NetBSD: patch-mpi_longlong.h,v 1.1 2015/04/17 14:36:17 sevan Exp $

Fix for compiling on Solaris SPARC with gcc.

 If __sparcv8 is defined, use the SPARC v8 version of udiv_qrnnd.  Without
 this change, udiv_qrnnd will not be defined using the SPARC v8 udiv
 instruction, and the default SPARC v7 case of defining it to be the native
 __gmpn_udiv_qrnnd will be used, but this does not exist on SPARC v8, so
 at link time, the user will get an error about _gmpn_udiv_qrnnd being
 undefined.  gcc defines __sparcv8.

From PR pkg/26815
https://bugs.g10code.com/gnupg/issue1703

--- mpi/longlong.h.orig	2015-04-17 14:24:14.000000000 +0000
+++ mpi/longlong.h
@@ -1287,7 +1287,7 @@ typedef unsigned int UTItype __attribute
 	     "rJ" ((USItype)(al)),                                      \
 	     "rI" ((USItype)(bl))                                       \
 	   __CLOBBER_CC)
-#if defined (__sparc_v8__)
+#if defined (__sparc_v8__) || defined(__sparcv8)
 /* Don't match immediate range because, 1) it is not often useful,
    2) the 'I' flag thinks of the range as a 13 bit signed interval,
    while we want to match a 13 bit interval, sign extended to 32 bits,
