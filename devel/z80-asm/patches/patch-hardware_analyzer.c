$NetBSD: patch-hardware_analyzer.c,v 1.1 2016/02/21 07:40:39 ryoon Exp $

--- hardware/analyzer.c.orig	2005-06-06 09:02:29.000000000 +0000
+++ hardware/analyzer.c
@@ -30,7 +30,7 @@ fprintf(fp,"%8s(%2x)  %c%c%c%c%c ", to_b
     '0'+cpu_pin[rd],
     '0'+cpu_pin[wr], '0'+cpu_pin[mreq], '0'+cpu_pin[iorq], '0'+cpu_pin[m1] );
 fprintf(fp," %c%c %c%c%c %c%c %c ",
-    '0'+cpu_pin[busrq],'0'+cpu_pin[busack],'0'+cpu_pin[wait],'0'+cpu_pin[halt],
+    '0'+cpu_pin[busrq],'0'+cpu_pin[busack],'0'+cpu_pin[mywait],'0'+cpu_pin[halt],
     '0'+cpu_pin[reset],'0'+IFF3,'0'+cpu_pin[inter],'0'+cpu_pin[rfsh]);
 if (cpu_pin[m1] && !last_m1)
    m1_counter++;
