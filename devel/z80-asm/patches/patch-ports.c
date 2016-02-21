$NetBSD: patch-ports.c,v 1.1 2016/02/21 07:40:39 ryoon Exp $

--- ports.c.orig	2005-06-10 16:41:45.000000000 +0000
+++ ports.c
@@ -62,9 +62,9 @@ out_byte(unsigned char id, unsigned char
 #endif
    if (!cpu_is_in_disassemble)
    {  wait_tics(TICS_MEMO);
-      set_cpu_pin(wait,1);
+      set_cpu_pin(mywait,1);
       wait_tics(TICS_WAIT);
-      set_cpu_pin(wait,0);
+      set_cpu_pin(mywait,0);
    }
    set_cpu_pin(iorq,0);
    set_cpu_pin(wr,0);
@@ -90,9 +90,9 @@ in_byte(unsigned char id, unsigned char 
    DATA= *data;
    if (!cpu_is_in_disassemble)
    {  wait_tics(TICS_MEMO);
-      set_cpu_pin(wait,1);
+      set_cpu_pin(mywait,1);
       wait_tics(TICS_WAIT);
-      set_cpu_pin(wait,0);
+      set_cpu_pin(mywait,0);
    }
    *data= DATA;
    set_cpu_pin(iorq,0);
