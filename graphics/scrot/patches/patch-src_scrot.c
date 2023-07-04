$NetBSD: patch-src_scrot.c,v 1.1 2023/07/04 15:05:20 jperkin Exp $

Pull in upstream fixes for platforms that lack dprintf().

--- src/scrot.c.orig	2023-06-10 17:55:55.000000000 +0000
+++ src/scrot.c
@@ -332,12 +332,14 @@ void scrotDoDelay(void)
     if (!opt.delay)
         return;
     if (opt.countdown) {
-        dprintf(STDERR_FILENO, "Taking shot in ");
+        fputs("Taking shot in ", stderr);
         for (int i = opt.delay; i > 0; i--) {
-            dprintf(STDERR_FILENO, "%d.. ", i);
+            fprintf(stderr, "%d.. ", i);
+            fflush(stderr);
             opt.delayStart = scrotSleepFor(opt.delayStart, 1000);
         }
-        dprintf(STDERR_FILENO, "0.\n");
+        fputs("0.\n", stderr);
+        fflush(stderr);
     } else {
         scrotSleepFor(opt.delayStart, opt.delay * 1000);
     }
