$NetBSD: patch-pandas-src-tseries.c,v 1.1 2012/11/22 00:15:13 bad Exp $

--- pandas/src/tseries.c.orig	2012-11-15 00:20:20.000000000 +0000
+++ pandas/src/tseries.c	2012-11-20 22:58:37.000000000 +0000
@@ -151203,7 +151203,7 @@
  * cdef int64_t _NS_UPPER_BOUND = -9223372036854775807LL
  * 
  */
-  __pyx_v_6pandas_3lib__NS_LOWER_BOUND = -9223285636854775809;
+  __pyx_v_6pandas_3lib__NS_LOWER_BOUND = -9223285636854775809LL;
 
   /* "/home/wesm/code/pandas/pandas/src/datetime.pyx":665
  * 
@@ -151212,7 +151212,7 @@
  * 
  * cdef inline _check_dts_bounds(int64_t value, pandas_datetimestruct *dts):
  */
-  __pyx_v_6pandas_3lib__NS_UPPER_BOUND = -9223372036854775807;
+  __pyx_v_6pandas_3lib__NS_UPPER_BOUND = -9223372036854775807LL;
 
   /* "/home/wesm/code/pandas/pandas/src/datetime.pyx":745
  *         raise ValueError('Unable to parse %s' % str(val))
