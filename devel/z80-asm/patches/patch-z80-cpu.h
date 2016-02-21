$NetBSD: patch-z80-cpu.h,v 1.1 2016/02/21 07:40:39 ryoon Exp $

--- z80-cpu.h.orig	2006-06-30 15:11:24.000000000 +0000
+++ z80-cpu.h
@@ -22,13 +22,13 @@ extern bit  IFF3;      /* NMI has occure
    m1       machine cycle one  (together with iorq acknowledges interrupt)
    inter    maskable interrupt pending
    halt     cpu in halt instruction
-   wait     cpu in wait state
+   mywait   cpu in wait state
    reset    cpu reset requested
    rfsh     cpu signals memory refresh (if mreq is set)
    busrq    external hardware requests bus control
    busack   cpu acknowledges bus control
 *********************/
-enum cpu_control_pin { rd, wr, iorq, mreq, m1, inter, halt, wait, reset, rfsh,
+enum cpu_control_pin { rd, wr, iorq, mreq, m1, inter, halt, mywait, reset, rfsh,
                        busrq, busack };
 extern const bit cpu_pin[NO_CPU_CONTROL_PINS];
 
