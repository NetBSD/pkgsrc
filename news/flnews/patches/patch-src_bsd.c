$NetBSD: patch-src_bsd.c,v 1.1 2019/01/21 12:03:41 wiz Exp $

Fixed typo. Only relevant for very old systems without inttypes.h header file.

--- src/bsd.c.orig	2017-11-08 12:11:18.000000000 +0000
+++ src/bsd.c
@@ -2,7 +2,7 @@
 /*! \file
  * \brief This is a wrapper to map BSD functionality of OS into POSIX subsystem
  *
- * Copyright (c) 2012-2015 by the developers. See the LICENSE file for details.
+ * Copyright (c) 2012-2019 by the developers. See the LICENSE file for details.
  *
  * BSD functions not defined in POSIX.1-1990 or XSI extension should be called
  * from here.
@@ -108,7 +108,7 @@ unsigned short int  posix_ntohs(unsigned
 #if CFG_HDR_INTTYPES_H
 uint32_t  posix_ntohl(uint32_t  net32)
 #else
-unsigned long int  posix_ntohs(unsigned long int  net32)
+unsigned long int  posix_ntohl(unsigned long int  net32)
 #endif  /* CFG_HDR_INTTYPES_H */
 {
    return(ntohl(net32));
