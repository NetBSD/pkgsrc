$NetBSD: patch-src_.mkmed-data_src_prjlibs-c_diewarn.h,v 1.1 2023/01/16 21:49:55 schmonz Exp $

Provide compatibility defines for skalibs 2.13.0.0 and up.

--- src/.mkmed-data/src/prjlibs-c/diewarn.h.orig	2021-04-30 07:37:06.416933193 +0000
+++ src/.mkmed-data/src/prjlibs-c/diewarn.h
@@ -1,6 +1,15 @@
 #ifndef PACKAGE__PROG__PRJLIBS__DIEWARN_H
 #define PACKAGE__PROG__PRJLIBS__DIEWARN_H
 
+#define strerr_die3x(e, x1, x2, x3) \
+strerr_die(e, x1, x2, (x3), 0, 0, 0, 0, 0, 0, 0, 0)
+#define strerr_die4x(e, x1, x2, x3, x4) \
+strerr_die(e, x1, x2, x3, (x4), 0, 0, 0, 0, 0, 0, 0)
+#define strerr_die5x(e, x1, x2, x3, x4, x5) \
+strerr_die(e, x1, x2, x3, x4, (x5), 0, 0, 0, 0, 0, 0)
+#define strerr_die6x(e, x1, x2, x3, x4, x5, x6) \
+strerr_die(e, x1, x2, x3, x4, x5, (x6), 0, 0, 0, 0, 0)
+
 #define DIE1X(status,x0)          strerr_die3x((status),PROG,": ",(x0))
 #define DIE2X(status,x0,x1)       strerr_die4x((status),PROG,": ",(x0),(x1))
 #define DIE3X(status,x0,x1,x2)    strerr_die5x((status),PROG,": ",(x0),(x1),\
@@ -76,12 +85,26 @@
 #define WARNTEXT1(op) WARNTEXT_unable(1, op) " "
 #define WARNTEXT2(op) WARNTEXT_unable(2, op) " "
 
+#define strerr_warn2sys(x1, x2) \
+strerr_warnsys(x1, (x2), 0, 0, 0, 0, 0, 0, 0, 0)
+#define strerr_warn4sys(x1, x2, x3, x4) \
+strerr_warnsys(x1, x2, x3, (x4), 0, 0, 0, 0, 0, 0)
+#define strerr_warn6sys(x1, x2, x3, x4, x5, x6) \
+strerr_warnsys(x1, x2, x3, x4, x5, (x6), 0, 0, 0, 0)
+
 #define WARN0(op)       strerr_warn2sys(PROG, WARNTEXT0(WARNTEXT0_##op))
 #define WARN1(op,x0)    strerr_warn4sys(PROG, WARNTEXT1(WARNTEXT1_##op), \
                                         (x0), ": ")
 #define WARN2(op,x0,x1) strerr_warn6sys(PROG, WARNTEXT2(WARNTEXT2_##op), \
                                         (x0), WARNSEP2_##op, (x1), ": ")
 
+#define strerr_die2sys(e, x1, x2) \
+strerr_diesys(e, x1, (x2), 0, 0, 0, 0, 0, 0, 0, 0)
+#define strerr_die4sys(e, x1, x2, x3, x4) \
+strerr_diesys(e, x1, x2, x3, (x4), 0, 0, 0, 0, 0, 0)
+#define strerr_die6sys(e, x1, x2, x3, x4, x5, x6) \
+strerr_diesys(e, x1, x2, x3, x4, x5, (x6), 0, 0, 0, 0)
+
 #define DIE0(op)       strerr_die2sys(DIESTAT(#op), PROG, \
                                       WARNTEXT0(WARNTEXT0_##op))
 #define DIE1(op,x0)    strerr_die4sys(DIESTAT(#op), PROG, \
