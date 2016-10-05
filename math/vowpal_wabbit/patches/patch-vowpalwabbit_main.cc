$NetBSD: patch-vowpalwabbit_main.cc,v 1.1.2.2 2016/10/05 18:20:57 bsiegert Exp $

--- vowpalwabbit/main.cc.orig	2016-09-30 09:21:08.000000000 +0000
+++ vowpalwabbit/main.cc
@@ -9,7 +9,7 @@ license as described in the file LICENSE
 #include <sys/socket.h>
 #include <arpa/inet.h>
 #endif
-#include <sys/timeb.h>
+#include <sys/time.h>
 #include "parse_args.h"
 #include "parse_regressor.h"
 #include "accumulate.h"
@@ -91,8 +91,8 @@ int main(int argc, char *argv[])
 
     vw& all = *alls[0];
 
-    struct timeb t_start, t_end;
-    ftime(&t_start);
+    struct timeval t_start, t_end;
+    gettimeofday(&t_start, NULL);
 
     VW::start_parser(all);
     if (alls.size() == 1)
@@ -102,10 +102,10 @@ int main(int argc, char *argv[])
 
     VW::end_parser(all);
 
-    ftime(&t_end);
-    double net_time = (int) (1000.0 * (t_end.time - t_start.time) + (t_end.millitm - t_start.millitm));
+    gettimeofday(&t_end, NULL);
+    double net_time = (t_end.tv_sec - t_start.tv_sec) + (t_end.tv_usec - t_start.tv_usec) * 0.000001;
     if(!all.quiet && all.all_reduce != nullptr)
-      cerr<<"Net time taken by process = "<<net_time/(double)(1000)<<" seconds\n";
+      cerr<<"Net time taken by process = "<<net_time<<" seconds\n";
 
     for (vw* v : alls)
     { VW::sync_stats(*v);
