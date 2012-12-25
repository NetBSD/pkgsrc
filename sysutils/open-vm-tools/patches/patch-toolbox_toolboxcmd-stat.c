$NetBSD: patch-toolbox_toolboxcmd-stat.c,v 1.1 2012/12/25 21:02:15 joerg Exp $

--- toolbox/toolboxcmd-stat.c.orig	2012-12-25 19:51:17.000000000 +0000
+++ toolbox/toolboxcmd-stat.c
@@ -96,10 +96,6 @@ Stat_ProcessorSpeed(void)
    bp.in.cx.halfs.low = BDOOR_CMD_GETMHZ;
    Backdoor(&bp);
    speed = bp.out.ax.word;
-   if (speed < 0) {
-      fprintf(stderr, "Unable to get processor speed\n");
-      return EX_TEMPFAIL;
-   }
    printf("%u MHz\n", speed);
    return EXIT_SUCCESS;
 }
@@ -130,10 +126,6 @@ Stat_MemorySize(void)
    bp.in.cx.halfs.low = BDOOR_CMD_GETMEMSIZE;
    Backdoor(&bp);
    memsize = bp.out.ax.word;
-   if (memsize < 0) {
-      fprintf(stderr, "Unable to get memory size\n");
-      return EX_TEMPFAIL;
-   }
    printf("%u MB\n", memsize);
    return EXIT_SUCCESS;
 }
@@ -166,10 +158,6 @@ Stat_HostTime(void)
    bp.in.cx.halfs.low = BDOOR_CMD_GETTIME;
    Backdoor(&bp);
    time = bp.out.ax.word;
-   if (time < 0) {
-      fprintf(stderr, "Unable to get host time\n");
-      return EX_TEMPFAIL;
-   }
    sprintf(buf, "%u", time);
    strptime(buf, "%s", &tm);
    strftime(buf, sizeof(buf), "%d %b %Y %H:%M:%S", &tm);
