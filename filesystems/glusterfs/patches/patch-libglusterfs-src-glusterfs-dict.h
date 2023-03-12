$NetBSD: patch-libglusterfs-src-glusterfs-dict.h,v 1.1 2023/03/12 17:57:44 js Exp $

Do not use __WORDSIZE as proxy for sizeof(time_t), since:
 - __WORDSIZE is glibc (and thus Linux) only
 - machine word size is a bad proxy for sizeof(time_t), e.g.
   NetBSD on 32bit arch (i386) also has sizeof(time_t) == 8

Instead use configure to check sizeof(time_t) and use this.

upstream bug https://github.com/gluster/glusterfs/issues/3942

--- libglusterfs/src/glusterfs/dict.h.orig      2023-01-01 23:19:50.909999764 +0100
+++ libglusterfs/src/glusterfs/dict.h   2023-01-01 23:09:15.920888776 +0100
@@ -15,6 +15,7 @@
 #include <sys/uio.h>
 #include <pthread.h>
 
+#include "config.h"
 #include "glusterfs/common-utils.h"
 
 typedef struct _data data_t;
@@ -320,17 +321,17 @@
 dict_set_uint64(dict_t *this, char *key, uint64_t val);
 
 /* POSIX-compliant systems requires the 'time_t' to be a signed integer. */
-#if __WORDSIZE == 64
+#if SIZEOF_TIME_T == 8
 #define dict_get_time(dict, key, val) dict_get_int64((dict), (key), (val))
 #define dict_set_time(dict, key, val) dict_set_int64((dict), (key), (val))
-#elif __WORDSIZE == 32
+#elif SIZEOF_TIME_T == 4
 #define dict_get_time(dict, key, val)                   \
     dict_get_int32((dict), (key), ((int32_t *)(val)))
 #define dict_set_time(dict, key, val)                   \
     dict_set_int32((dict), (key), ((int32_t)(val)))
 #else
 #error "unknown word size"
-#endif /* WORDSIZE check */
+#endif /* SIZEOF_TIME_T check */
 
 GF_MUST_CHECK int
 dict_check_flag(dict_t *this, char *key, int flag);
