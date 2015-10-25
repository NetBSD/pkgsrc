$NetBSD: patch-include_vlc__common.h,v 1.1 2015/10/25 11:00:18 wiz Exp $

--- include/vlc_common.h.orig	2014-11-16 18:57:58.000000000 +0000
+++ include/vlc_common.h
@@ -47,6 +47,9 @@
 #include <stdio.h>
 #include <inttypes.h>
 #include <stddef.h>
+#ifdef __NetBSD__
+#include <sys/param.h>
+#endif
 
 #ifndef __cplusplus
 # include <stdbool.h>
@@ -541,6 +544,8 @@ static inline unsigned ctz (unsigned x)
 #endif
 }
 
+#if !defined(__NetBSD_Version__) || (__NetBSD_Version__ < 599001600)
+
 /** Bit weight */
 VLC_USED
 static inline unsigned popcount (unsigned x)
@@ -557,6 +562,7 @@ static inline unsigned popcount (unsigne
     return count;
 #endif
 }
+#endif /* NetBSD < 5.99.16 */
 
 VLC_USED
 static inline unsigned parity (unsigned x)
@@ -576,6 +582,8 @@ static inline unsigned parity (unsigned 
 #   undef bswap64
 #endif
 
+#ifndef __NetBSD__
+
 /** Byte swap (16 bits) */
 VLC_USED
 static inline uint16_t bswap16 (uint16_t x)
@@ -624,6 +632,7 @@ static inline uint64_t bswap64 (uint64_t
 #endif
 }
 
+#endif /* NetBSD */
 
 /* Free and set set the variable to NULL */
 #define FREENULL(a) do { free( a ); a = NULL; } while(0)
