$NetBSD: patch-sim__timer.h,v 1.1 2012/07/16 00:14:33 abs Exp $

Relax granularity check to allow setting idle on a machine with HZ 100

--- sim_timer.h.orig	2008-11-21 20:06:34.000000000 +0000
+++ sim_timer.h
@@ -35,7 +35,7 @@
 #define SIM_TMAX        500                             /* max timer makeup */
 
 #define SIM_IDLE_CAL    10                              /* ms to calibrate */
-#define SIM_IDLE_MAX    10                              /* max granularity idle */
+#define SIM_IDLE_MAX    20                              /* max granularity idle */
 #define SIM_IDLE_STMIN  10                              /* min sec for stability */
 #define SIM_IDLE_STDFLT 20                              /* dft sec for stability */
 #define SIM_IDLE_STMAX  600                             /* max sec for stability */
