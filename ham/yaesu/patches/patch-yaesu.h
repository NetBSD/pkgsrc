$NetBSD: patch-yaesu.h,v 1.1 2012/11/19 23:15:10 joerg Exp $

--- yaesu.h.orig	2012-11-19 16:04:48.000000000 +0000
+++ yaesu.h
@@ -0,0 +1,48 @@
+#include <ctype.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <unistd.h>
+void stat_out(int fdSer, int current_freq_mode);
+void mem_scsk(int fdSer);
+void wwv_find(int fdSer);
+void mem_hide(int fdSer);
+void mem_save(int fdSer);
+void outport(int fdSer, int one, int two, int three, int four, int opcode);
+void stat_upd(int fdSer);
+void rd_flags(int fdSer);
+void pacing(int fdSer);
+void aux(int fdSer);
+void ctcss(int fdSer);
+void rptr_off(int fdSer);
+void ham_gen(int fdSer);
+void clar(int fdSer);
+void vfo_a2b(int fdSer);
+void step(int fdSer);
+void strt_tun(int fdSer);
+void tuner10(int fdSer);
+void mem_2vfo(int fdSer);
+void vfo_ab(int fdSer);
+void lock(int fdSer);
+void vfo_2mem(int fdSer);
+void mem_rec(int fdSer);
+void ptt(int fdSer);
+void bright(int fdSer);
+void mode (int fdSer);
+void freq_out(int fdSer);
+void repeater_simplex(int fdSer);
+int meter_rd(int fdSer);
+void splt_tog(int fdSer);
+void yaesu(int fdSer);
+
+extern int aux_comeback;
+extern char data_array[650];
+extern int memory_number;
+extern int data_return_param;
+extern char flag_data_return[5];
+extern float freq_to_change_to;
+
+extern char narrow1, narrow2, narrow3, narrow4, narrow5, narrow6;
+extern char white_space;
+extern char mode1, mode2, mode3;
+extern int yaesu_return;
