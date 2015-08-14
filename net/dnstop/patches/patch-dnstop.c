$NetBSD: patch-dnstop.c,v 1.1 2015/08/14 21:21:24 leot Exp $

Avoid incompatible types assignments.

--- dnstop.c.orig	2014-09-15 17:54:51.000000000 +0000
+++ dnstop.c
@@ -188,11 +188,7 @@ hashtbl *DomSrcs[10];
 hashtbl *KnownTLDs = NULL;
 hashtbl *NewGTLDs = NULL;
 
-#ifdef HAVE_STRUCT_BPF_TIMEVAL
-struct bpf_timeval last_ts;
-#else
 struct timeval last_ts;
-#endif
 time_t report_interval = 1;
 
 /*
