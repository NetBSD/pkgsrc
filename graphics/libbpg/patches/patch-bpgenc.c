$NetBSD: patch-bpgenc.c,v 1.1.1.1 2014/12/12 22:05:04 agc Exp $

Just use getopt_long(3) for now

--- bpgenc.c	2014/12/12 21:34:04	1.1
+++ bpgenc.c	2014/12/12 21:34:20
@@ -1862,7 +1862,7 @@
     encoder_type = 0;
 
     for(;;) {
-        c = getopt_long_only(argc, argv, "q:o:hf:c:vm:b:e:", long_opts, &option_index);
+        c = getopt_long(argc, argv, "q:o:hf:c:vm:b:e:", long_opts, &option_index);
         if (c == -1)
             break;
         switch(c) {
