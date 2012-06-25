$NetBSD: patch-qof_qofmath128.h,v 1.1 2012/06/25 11:26:28 joerg Exp $

--- qof/qofmath128.h.orig	2012-06-18 15:51:31.000000000 +0000
+++ qof/qofmath128.h
@@ -44,45 +44,45 @@ typedef struct
 } QofInt128;
 
 /** Return true of two numbers are equal */
-inline gboolean equal128 (QofInt128 a, QofInt128 b);
+gboolean equal128 (QofInt128 a, QofInt128 b);
 
 /** Return returns 1 if a>b, -1 if b>a, 0 if a == b */
-inline gint cmp128 (QofInt128 a, QofInt128 b);
+gint cmp128 (QofInt128 a, QofInt128 b);
 
 /** Shift right by one bit (i.e. divide by two) */
-inline QofInt128 shift128 (QofInt128 x);
+QofInt128 shift128 (QofInt128 x);
 
 /** Shift left by one bit (i.e. multiply by two) */
-inline QofInt128 shiftleft128 (QofInt128 x);
+QofInt128 shiftleft128 (QofInt128 x);
 
 /** Increment by one */
-inline QofInt128 inc128 (QofInt128 a);
+QofInt128 inc128 (QofInt128 a);
 
 /** Add a pair of 128-bit numbers, returning a 128-bit number */
-inline QofInt128 add128 (QofInt128 a, QofInt128 b);
+QofInt128 add128 (QofInt128 a, QofInt128 b);
 
 /** Multiply a pair of signed 64-bit numbers, 
  *  returning a signed 128-bit number.
  */
-inline QofInt128 mult128 (gint64 a, gint64 b);
+QofInt128 mult128 (gint64 a, gint64 b);
 
 /** Divide a signed 128-bit number by a signed 64-bit,
  *  returning a signed 128-bit number.
  */
-inline QofInt128 div128 (QofInt128 n, gint64 d);
+QofInt128 div128 (QofInt128 n, gint64 d);
 
 /** Return the remainder of a signed 128-bit number modulo 
  *  a signed 64-bit.  That is, return n%d in 128-bit math.
  *  I beleive that ths algo is overflow-free, but should be 
  *  audited some more ... 
  */
-inline gint64 rem128 (QofInt128 n, gint64 d);
+gint64 rem128 (QofInt128 n, gint64 d);
 
 /** Return the greatest common factor of two 64-bit numbers */
-inline guint64 gcf64 (guint64 num, guint64 denom);
+guint64 gcf64 (guint64 num, guint64 denom);
 
 /** Return the least common multiple of two 64-bit numbers. */
-inline QofInt128 lcm128 (guint64 a, guint64 b);
+QofInt128 lcm128 (guint64 a, guint64 b);
 
 /** @} */
 /** @} */
